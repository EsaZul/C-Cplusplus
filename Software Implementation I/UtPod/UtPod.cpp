#include "UtPod.h"
#include "Song.h"
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

UtPod::UtPod()
{
    podMemSize = MAX_MEMORY;
}

UtPod::UtPod(int size)
{
    if ((size > MAX_MEMORY) || (size <= 0)){
        podMemSize = MAX_MEMORY;
    }
    else {
        podMemSize = size;
    }
    songs = NULL;
}

//Helper functions

int UtPod::numSongs() {              //Counts the number of Songs, used for shuffle
    int count = 0;
    SongNode *ptr = songs;
    while (ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
}

void UtPod::swap(Song &s1, Song &s2) {                  //MAnolo test okay
    Song temp = s2;
    s2 = s1;
    s1 = temp;
}



//Main functions

int UtPod::addSong(Song const &s) {                                 //Manolo test okay
    if ((s.getSize() > getRemainingMemory())) {
        return NO_MEMORY;
    }
    else if ((s.getArtist()=="") || (s.getTitle()=="") || (s.getSize() <= 0)){
        return NOT_FOUND;
    }
    SongNode *tail = songs;
    SongNode *temp = new SongNode;
    temp->s = s;
    temp->next = NULL;
    if (songs == NULL) {
        songs = temp;
    }
    else {
        SongNode *p1 = tail->next;
        while (p1 != NULL) {
            tail = tail->next;
            p1 = p1->next;
        }
        tail->next = temp;
    }
    return SUCCESS;
}

int UtPod::removeSong(Song const &s) {              //MAnolo Test okay
    SongNode *p1 = songs;

    if (p1 == NULL) {
        return NOT_FOUND;
    }
    else if (p1->s == s) {
        songs = p1->next;
        delete p1;
    }
    else {
        SongNode *p2 = p1->next;
        while (!(p2->s == s)){
            p1 = p1->next;
            p2 = p2->next;
            if (p2 == NULL) {
                return NOT_FOUND;
            }
        }
        p1->next = p2->next;
        delete p2;
    }
    return SUCCESS;
}

void UtPod::shuffle() {                         //shuffle is like sort
    int count = numSongs();
    SongNode *ptr1, *ptr2;
    ptr1 = songs;
    ptr2 = songs;
    srand(time(NULL));
    for (int i = 0; i < count; i++){
        int num1 = rand() % count;
        int num2 = rand() % count;
        while ((num1 == num2) && (num1 !=0)) {
            num2 = (num2 + 1) % count;
        }
        for(int j = 0; j < num1; j++){
            ptr1 = ptr1->next;
        }
        for(int j = 0; j < num2; j++){
            ptr2 = ptr2->next;
        }

        swap(ptr2->s,ptr1->s);
        ptr1 = songs;
        ptr2 = songs;
    }
}

void UtPod::showSongList() {                                            //Manolo test okay
    for (SongNode *ptr = songs; ptr != NULL; ptr = ptr->next) {
        cout << (ptr->s).getArtist() << " - " << (ptr->s).getTitle() << " [size: " << (ptr->s).getSize() << "MB]"
             << endl;
    }
    cout << endl;
}

void UtPod::sortSongList(){                                             //Manolo test okay
    for (SongNode *p1 = songs; p1 != NULL; p1 = p1->next){
        for (SongNode *p2 = p1->next; p2 != NULL; p2 = p2->next) {
            if (p2->s < p1->s) {
                swap(p2->s, p1->s);
            }
        }
    }
}
void UtPod::clearMemory() {                         //Manolo test okay
    int count = numSongs();
    for (int i = 0; i < count; i++) {
        removeSong(songs->s);
    }
}

int UtPod::getRemainingMemory() {                   //Manolo test okay
    int memLeft = podMemSize;
    for (SongNode *ptr = songs; ptr != NULL; ptr = ptr->next){
        memLeft -= (ptr->s).getSize();
    }
    return memLeft;
}

UtPod::~UtPod() {                                   //Manolo test okay
    clearMemory();
    delete songs;
}



