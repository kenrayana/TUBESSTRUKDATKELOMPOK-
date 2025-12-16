// ===================== player.h =====================
#ifndef PLAYER_H
#define PLAYER_H


#include "songlibrary.h"
#include "playlist.h"
#include <iostream>
using namespace std;


enum PlayMode {
NONE,
FROM_LIBRARY,
FROM_PLAYLIST
};


struct Player {
SongNode* currentLibrary;
PlaylistNode* currentPlaylist;
PlayMode mode;
bool isPlaying;


Player() {
currentLibrary = nullptr;
currentPlaylist = nullptr;
mode = NONE;
isPlaying = false;
}
};

void playFromLibrary(Player& p, SongLibrary& lib, int id);
void nextSongLibrary(Player& p);
void previousSongLibrary(Player& p);


void playFromPlaylist(Player& p, Playlist* pl, int index);
void nextSongPlaylist(Player& p);
void previousSongPlaylist(Player& p);


void stopSong(Player& p);


#endif
