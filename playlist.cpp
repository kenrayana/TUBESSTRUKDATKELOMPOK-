#include "playlist.h"
#include "usernode.h"
#include <iostream>
using namespace std;

void addPlaylist(UserNode* user, string nama) {
    Playlist* p = new Playlist(nama);
    p->next = user->firstPlaylist;
    user->firstPlaylist = p;
}

void addSongToPlaylist(Playlist* pl, SongNode* song) {
    if (!pl || !song) return;

    PlaylistNode* node = new PlaylistNode(song);
    if (!pl->head) {
        pl->head = pl->tail = node;
    } else {
        pl->tail->next = node;
        node->prev = pl->tail;
        pl->tail = node;
    }
}

bool removeSongFromPlaylist(Playlist* pl, int id) {
    if (!pl || !pl->head) return false;

    PlaylistNode* cur = pl->head;
    while (cur) {
        if (cur->song->id == id) {
            if (cur == pl->head) pl->head = cur->next;
            if (cur == pl->tail) pl->tail = cur->prev;
            if (cur->prev) cur->prev->next = cur->next;
            if (cur->next) cur->next->prev = cur->prev;
            delete cur;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

void showPlaylist(Playlist* pl) {
    if (!pl || !pl->head) {
        cout << "Playlist kosong\n";
        return;
    }

    PlaylistNode* cur = pl->head;
    while (cur) {
        cout << "[" << cur->song->id << "] "
             << cur->song->title << " - "
             << cur->song->artist << endl;
        cur = cur->next;
    }
}

void removeSongFromAllPlaylists(UserNode* user, int songID) {
    while (user) {
        Playlist* pl = user->firstPlaylist;
        while (pl) {
            removeSongFromPlaylist(pl, songID);
            pl = pl->next;
        }
        user = user->next;
    }
}

Playlist* choosePlaylist(UserNode* user) {
    if (!user || !user->firstPlaylist) return nullptr;

    Playlist* p = user->firstPlaylist;
    int i = 1;

    cout << "\nPilih Playlist:\n";
    while (p) {
        cout << i << ". " << p->nama << endl;
        p = p->next;
        i++;
    }

    int pilih;
    cout << "Pilihan: ";
    cin >> pilih;

    p = user->firstPlaylist;
    for (int j = 1; j < pilih && p; j++)
        p = p->next;

    return p;
}

