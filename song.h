#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

struct Song {
    int id;
    string judul;
    string penyanyi;
    string genre;
    string reff;
    string durasi;

    Song() {}

    Song(int i, string j, string p, string g, string r, string d) {
        id = i;
        judul = j;
        penyanyi = p;
        genre = g;
        reff = r;
        durasi = d;
    }
};

#endif
