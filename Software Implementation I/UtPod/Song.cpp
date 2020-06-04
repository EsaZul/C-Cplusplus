#include "Song.h"
#include <string>

using namespace std;

Song::Song(){
    title = "Unnamed";
    artist = "Untitled";
    size = DEFAULT_SIZE;
};

Song::Song(string _artist, string _title, int _size){
    artist = _artist;
    title = _title;
    size = _size;
}

void Song::setArtist(string _artist) {
    artist = _artist;
}

void Song::setTitle(string _title) {
    title = _title;
}

void Song::setSize(int _size){
    size = _size;
}

string Song::getArtist() const {
    return artist;
}

string Song::getTitle() const {
    return title;
}

int Song::getSize() const {
    return size;
}


bool Song::operator >(Song const &rhs){
    if (artist > rhs.artist){
        return true;
    }
    else if ((artist ==  rhs.artist) && (title > rhs.title)){
        return true;
    }
    else if ((artist == rhs.artist) && (title == rhs.title) && (size > rhs.size)){
        return true;
    }
    else {
        return false;
    }
}

bool Song::operator <(Song const &rhs) {
    if (artist < rhs.artist) {
        return true;
    }
    else if ((artist == rhs.artist) && (title < rhs.title)) {
        return true;
    }
    else if ((artist == rhs.artist) && (title == rhs.title) && (size < rhs.size)) {
        return true;
    }
    else {
        return false;
    }
}

bool Song::operator ==(Song const &rhs){
    return ((artist == rhs.artist) && (title == rhs.title) && (size == rhs.size));
}


