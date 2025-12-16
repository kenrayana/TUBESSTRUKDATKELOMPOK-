#ifndef ADMIN_H
#define ADMIN_H

#include "usernode.h"

struct Admin {
    UserNode* firstUser;
};

// Inisialisasi admin
void initAdmin(Admin &admin);

// Menambah user
void addUser(Admin &admin, string username);

// Mencari user
UserNode* findUser(Admin &admin, string username);

// Menampilkan semua user
void showAllUsers(Admin &admin);
void showAllPlaylists(UserNode* user);


#endif
