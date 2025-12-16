#include <iostream>
#include "player.h"
#include "playlist.h"


void playFromLibrary(Player& p, SongLibrary& lib, int id) {
    SongNode* song = lib.findSongByID(id);
    if (!song) {
        cout << "Lagu tidak ditemukan" << endl;
        return;
    }
    p.currentLibrary = song;
    p.currentPlaylist = nullptr;
    p.mode = FROM_LIBRARY;
    p.isPlaying = true;

    cout << "\n▶ PLAY (LIBRARY)" << endl;
    cout << song->title << " - " << song->artist << endl;
    cout << "Reff: " << song->lyric << endl;
}

void nextSongLibrary(Player& p) {
    if (p.mode != FROM_LIBRARY || !p.currentLibrary) return;
    if (p.currentLibrary->next) {
        p.currentLibrary = p.currentLibrary->next;
        cout << "\n▶ NEXT (LIBRARY)" << endl;
        cout << p.currentLibrary->title << " - " << p.currentLibrary->artist << endl;
    } else {
        cout << "Sudah lagu terakhir di library" << endl;
    }
}

void previousSongLibrary(Player& p) {
    if (p.mode != FROM_LIBRARY || !p.currentLibrary) return;
    if (p.currentLibrary->prev) {
        p.currentLibrary = p.currentLibrary->prev;
        cout << "\n▶ PREVIOUS (LIBRARY)" << endl;
        cout << p.currentLibrary->title << " - " << p.currentLibrary->artist << endl;
    } else {
        cout << "Sudah lagu pertama di library" << endl;
    }
}

void playFromPlaylist(Player& p, Playlist* pl, int index) {
    if (!pl || !pl->head) return;

    PlaylistNode* cur = pl->head;
    int i = 1;
    while (cur && i < index) {
        cur = cur->next;
        i++;
    }
    if (!cur) return;

    p.currentPlaylist = cur;
    p.currentLibrary = nullptr;
    p.mode = FROM_PLAYLIST;
    p.isPlaying = true;

    cout << "\n▶ PLAY (PLAYLIST: " << pl->nama << ")" << endl;
    cout << cur->song->title << " - " << cur->song->artist << endl;
    cout << "Reff: " << cur->song->lyric << endl;
}

void nextSongPlaylist(Player& p) {
    if (p.mode != FROM_PLAYLIST || !p.currentPlaylist) return;
    if (p.currentPlaylist->next) {
        p.currentPlaylist = p.currentPlaylist->next;
        cout << "\n▶ NEXT (PLAYLIST)" << endl;
        cout << p.currentPlaylist->song->title << endl;
    } else {
        cout << "Sudah lagu terakhir di playlist" << endl;
    }
}

void previousSongPlaylist(Player& p) {
    if (p.mode != FROM_PLAYLIST || !p.currentPlaylist) return;
    if (p.currentPlaylist->prev) {
        p.currentPlaylist = p.currentPlaylist->prev;
        cout << "\n▶ PREVIOUS (PLAYLIST)" << endl;
        cout << p.currentPlaylist->song->title << endl;
    } else {
        cout << "Sudah lagu pertama di playlist" << endl;
    }
}

void stopSong(Player& p) {
    p.currentLibrary = nullptr;
    p.currentPlaylist = nullptr;
    p.mode = NONE;
    p.isPlaying = false;
    cout << "⏹ STOP" << endl;
}

