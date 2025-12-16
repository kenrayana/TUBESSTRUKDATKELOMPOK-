#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include "playlistnode.h"

using namespace std;

struct UserNode;

struct Playlist {
    string nama;
    PlaylistNode* head;
    PlaylistNode* tail;
    Playlist* next;

    Playlist(string n="") {
        nama = n;
        head = tail = nullptr;
        next = nullptr;
    }
};

void addPlaylist(UserNode* user, string nama);
void addSongToPlaylist(Playlist* pl, SongNode* song);
bool removeSongFromPlaylist(Playlist* pl, int id);
void showPlaylist(Playlist* pl);
void removeSongFromAllPlaylists(UserNode* user, int songID);
Playlist* choosePlaylist(UserNode* user);



#endif
