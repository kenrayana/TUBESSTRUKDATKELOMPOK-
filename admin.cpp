#include <iostream>
#include "admin.h"
using namespace std;

void initAdmin(Admin &admin) {
    admin.firstUser = nullptr;
}

void addUser(Admin &admin, string username) {
    UserNode* u = new UserNode(username);
    u->next = admin.firstUser;
    admin.firstUser = u;
    cout << "User '" << username << "' berhasil ditambahkan\n";
}

UserNode* findUser(Admin &admin, string username) {
    UserNode* cur = admin.firstUser;
    while (cur) {
        if (cur->username == username) return cur;
        cur = cur->next;
    }
    return nullptr;
}

void showAllUsers(Admin &admin) {
    UserNode* cur = admin.firstUser;
    while (cur) {
        cout << "- " << cur->username << endl;
        cur = cur->next;
    }
}

void showAllPlaylists(UserNode* user) {
    Playlist* p = user->firstPlaylist;
    int i = 1;
    while (p) {
        cout << i++ << ". " << p->nama << endl;
        p = p->next;
    }
}
