#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song {

    private:
        string artist;
        string title;
        int size;

        static const int DEFAULT_SIZE = 0;


    public:

        Song();

        Song(string _title, string _artist, int _size); //creates a song

        void setArtist(string _artist);                 //input artist personally

        void setTitle(string _title);                   //input title of song personally

        void setSize(int _size);                        //input size of song

        string getArtist() const;                       //receives the artist name

        string getTitle() const;                        //receives title of song

        int getSize() const;                            //receives the size of the song


        bool operator >(Song const &rhs);               //compares the songs depending on artist name length,
        bool operator <(Song const &rhs);               //then title length, then size length
        bool operator ==(Song const &rhs);
};

#endif