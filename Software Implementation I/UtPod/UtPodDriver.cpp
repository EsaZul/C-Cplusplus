/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Creating UtPod of default size ... " << endl << endl;
    UtPod t;
    cout << "Created" << endl;
    cout << "memory size = " << t.getTotalMemory() << endl << endl;

    Song s1("Imagine Dragons", "Thunder", 4);
    Song s2("Post Malone", "Rockstar", 3);
    Song s3("Ariana Grande", "No Tears Left to Cry", 5);
    Song s4("Maroon 5", "Wait", 3);
    Song s5("Maroon 5", "She Will Be Loved", 4);
    Song s6("Post Malone", "Sunflower", 4);
    Song s7("Maroon 5", "Sunday Morning", 5);
    Song s8("Imagine Dragons", "Demons", 4);
    Song s9("Post Malone", "Psycho", 5);
    Song s10("Ed Sheeran", "Lego House", 4);
    Song s11("Imagine Dragons", "Bad Liar", 5);
    Song s12("Jonas Brothers", "Sucker", 3);
    Song s13("Jonas Brothers", "Lovebug", 4);
    Song s14("Imagine Dragons", "Radioactive", 3);
    Song s15("Nick Jonas", "Levels", 5);
    Song s16("Marvel", "Avengers", 491);
    Song s17("Marvel", "Avengers with Bloopers", 547);
    Song s18("","",0);

    int result = 0;

    cout << "Adding All Songs (except Avengers) ... " << endl;

    result += t.addSong(s1);
    result += t.addSong(s2);
    result += t.addSong(s3);
    result += t.addSong(s4);
    result += t.addSong(s5);
    result += t.addSong(s6);
    result += t.addSong(s7);
    result += t.addSong(s8);
    result += t.addSong(s9);
    result += t.addSong(s10);
    result += t.addSong(s11);
    result += t.addSong(s12);
    result += t.addSong(s13);
    result += t.addSong(s14);
    result += t.addSong(s15);

    cout << "result = " << result << endl;
    cout << "Program working if result = 0" << endl << endl;
    cout << "Showing added songs ... " << endl << endl;

    t.showSongList();

    cout << "Sorting songs and showing ... " << endl << endl;

    t.sortSongList();
    t.showSongList();

    cout << "Program working if songs are sorted by artist, then title, then size" << endl << endl;
    cout << "Shuffling songs and showing ... " << endl << endl;

    t.shuffle();
    t.showSongList();

    cout << "Program working if the song list is shuffled" << endl << endl;

    cout << "Shuffling songs again and showing ... " << endl << endl;

    t.shuffle();
    t.showSongList();

    cout << "Program working if the song list is shuffled again" << endl << endl;

    cout << "Trying to add Avengers, program working if result = -1" << endl << endl;

    result += t.addSong(s16);

    cout << "result = " << result << endl;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Size of Avengers was 491 MB, -1 is the no memory error" << endl << endl;

    cout << "Clearing memory ..." << endl << endl;
    t.clearMemory();
    t.showSongList();
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Program working if no songs printed above this line and remaining memory = 512" << endl << endl;

    cout << "Resetting result to 0, adding certain songs and showing them ..." << endl << endl;

    result = 0;
    result += t.addSong(s1);
    result += t.addSong(s2);
    result += t.addSong(s3);
    result += t.addSong(s4);
    result += t.addSong(s5);
    result += t.addSong(s6);
    result += t.addSong(s7);
    result += t.addSong(s8);
    result += t.addSong(s9);
    result += t.addSong(s9);

    t.showSongList();

    cout << "result = " << result << endl;
    cout << "Program working if result = 0 and songs displayed" << endl << endl;

    cout << "(Psycho 5 MB version added twice)" << endl << endl;

    cout << "Sorting songs and showing ..." << endl << endl;

    t.sortSongList();
    t.showSongList();

    cout << "Different instances of same song should have sorted accordingly" << endl << endl;
    cout << "Removing Sunday Morning and Rockstar ... " << endl << endl;

    result += t.removeSong(s2);
    result += t.removeSong(s7);
    t.showSongList();
    cout << "result = " << result << endl;
    cout << "Program working if result = 0 and removed songs not displayed" << endl << endl;

    cout << "Removing Demons and Wait (the first and last songs) ... " << endl << endl;

    result += t.removeSong(s4);
    result += t.removeSong(s8);
    t.showSongList();
    cout << "result = " << result << endl;
    cout << "Program working if result = 0 and removed songs not displayed" << endl << endl;

    cout << "Trying to remove Sunday Morning again ..." << endl << endl;
    result += t.removeSong(s7);

    cout << "result = " << result << endl;
    cout << "Program working if result = -2" << endl;
    cout << "Tried to remove Sunday Morning, but it is not in the UtPod, -2 is the not found error" << endl << endl;

    cout << "Resetting result to 0, removing one instance of the 5 MB version of Psycho ... " << endl << endl;

    result = 0;
    result += t.removeSong(s9);
    t.showSongList();
    cout << "result = " << result << endl;
    cout << "Program working if result = 0 and only one 5 MB version of Psycho is displayed" << endl << endl;

    cout << "Shuffling songs again and showing ..." << endl << endl;
    t.shuffle();
    t.showSongList();
    cout << "Program working if the song list is shuffled" << endl << endl;

    cout << "Clearing memory ..." << endl << endl;
    t.clearMemory();
    t.showSongList();
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Program working if no songs printed above this line and remaining memory = 512" << endl << endl;

    cout << "Trying to remove a song when there are no songs ..." << endl << endl;
    result += t.removeSong(s4);
    cout << "result = " << result << endl;
    cout << "Program working if result = -2, which is the not found error" << endl << endl;

    cout << "Resetting result to 0 and adding the Avengers and showing the song list ... " << endl << endl;
    result = 0;
    result += t.addSong(s16);
    t.showSongList();
    cout << "result = " << result << endl;
    cout << "Program working if result = 0 and the Avengers is displayed" << endl << endl;

    cout << "Shuffling the song list with one song ..." << endl << endl;
    t.shuffle();
    t.showSongList();

    cout << "Program working if the only song is displayed" << endl << endl;

    cout << "Sorting the song list with one song ..." << endl << endl;
    t.sortSongList();
    t.showSongList();

    cout << "Program working if the only song is displayed" << endl << endl;

    cout << "Removing the Avengers ..." << endl << endl;
    t.removeSong(s16);
    t.showSongList();
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Program working if no songs printed above this line and remaining memory = 512" << endl << endl;

    cout << "Trying to add the Avengers with Bloopers ... " << endl << endl;

    result += t.addSong(s17);
    t.showSongList();

    cout << "result = " << result << endl;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Program working if result = -1, remaining memory = 512 and no songs printed above this line" << endl;
    cout << "Size of Avengers with Bloopers was 547 MB, maximum capacity of UtPod is 512 MB, -1 is the no memory error" << endl << endl;

    cout << "Resetting result to 0, reading three songs and showing ... " << endl << endl;

    result = 0;
    result += t.addSong(s1);
    result += t.addSong(s2);
    result += t.addSong(s3);
    t.showSongList();

    cout << "result = " << result << endl;
    cout << "Program working if result = 0" << endl;

    cout << "Destructing UtPod and reconstructing with 256 MB ... " << endl << endl;

    t.~UtPod();
    new(&t) UtPod(256);
    t.showSongList();

    cout << "memory size = " << t.getTotalMemory() << endl;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Program working if remaining memory and memory size = 256 and no songs printed above this line" << endl << endl;

    cout << "Trying to add the Avengers ... " << endl << endl;

    result += t.addSong(s16);
    t.showSongList();

    cout << "result = " << result << endl;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Program working if result = -1, remaining memory = 256 and no songs printed above this line" << endl;
    cout << "Size of Avengers was 491 MB, maximum capacity of UtPod is 256 MB, -1 is the no memory error" << endl << endl;

    cout << "Destructing UtPod and reconstructing with 4 MB ... " << endl << endl;

    t.~UtPod();
    new(&t) UtPod(4);
    t.showSongList();
    result = 0;

    cout << "memory size = " << t.getTotalMemory() << endl;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Program working if remaining memory and memory size = 4 and no songs printed above this line" << endl << endl;

    cout << "Trying to add Sunday Morning ... " << endl << endl;

    result += t.addSong(s7);
    t.showSongList();

    cout << "result = " << result << endl;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;
    cout << "Program working if result = -1, remaining memory = 4 and no songs printed above this line" << endl;
    cout << "Size of Sunday Morning was 5 MB, maximum capacity of UtPod is 4 MB, -1 is the no memory error" << endl << endl;

    cout << "Adding My Last to Girls Like You by Maroon 5 with a size of 2 MB, adding to the UtPod and showing ... " << endl << endl;
    s2.setArtist("Maroon 5");
    s2.setTitle("Girls Like You");
    s2.setSize(2);
    result = 0;
    result += t.addSong(s2);
    t.showSongList();

    cout << "result = " << result << endl;
    cout << "Program working if result = 0 and Girls Like You is displayed" << endl << endl;

    cout << "Clearing memory ..." << endl;
    t.clearMemory();
    cout << "Trying to add song with blank artist and title and 0 size ..." << endl << endl;
    result += t.addSong(s18);
    cout << "result = " << result << endl;
    cout << "Program working if result = -2" << endl;

    t.~UtPod();

}