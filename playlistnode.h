#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H

#include "songnode.h"

struct PlaylistNode {
    SongNode* song;
    PlaylistNode* prev;
    PlaylistNode* next;

    PlaylistNode(SongNode* s) {
        song = s;
        prev = next = nullptr;
    }
};

#endif
