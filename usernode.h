#ifndef USERNODE_H
#define USERNODE_H

#include <string>
#include "playlist.h"
#include "player.h"

using namespace std;

struct UserNode {
    string username;
    Playlist* firstPlaylist;
    Player* player;
    UserNode* next;

    UserNode(string u) {
        username = u;
        firstPlaylist = nullptr;
        player = nullptr;
        next = nullptr;
    }
};

#endif
