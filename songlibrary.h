#ifndef SONGLIBRARY_H
#define SONGLIBRARY_H

#include "songnode.h"
#include <string>
using namespace std;

struct Admin;

struct SongLibrary {
    SongNode* head;
    SongNode* tail;
    int autoID;

    SongLibrary();

    void addSong(string title,
                 string artist,
                 string genre,
                 string duration,
                 string lyric);

    void showLibrary();
    SongNode* findSongByID(int id);

    bool updateSong(int id,
                    string title,
                    string artist,
                    string genre,
                    string duration,
                    string lyric);

    bool deleteSong(int id, Admin& admin);
};

void seedDefaultSongs(SongLibrary& lib);

#endif
