#ifndef SONGNODE_H
#define SONGNODE_H

#include <string>
using namespace std;

struct SongNode {
    int id;
    string title;
    string artist;
    string genre;
    string duration;
    string lyric;

    SongNode* prev;
    SongNode* next;

    SongNode(int _id,
             string _title,
             string _artist,
             string _genre,
             string _duration,
             string _lyric) {
        id = _id;
        title = _title;
        artist = _artist;
        genre = _genre;
        duration = _duration;
        lyric = _lyric;
        prev = next = nullptr;
    }
};

#endif
