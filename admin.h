#ifndef ADMIN_H
#define ADMIN_H

#include "usernode.h"

struct Admin {
    UserNode* firstUser;
};

void initAdmin(Admin &admin);
void addUser(Admin &admin, string username);
UserNode* findUser(Admin &admin, string username);
void showAllUsers(Admin &admin);
void showAllPlaylists(UserNode* user);

#endif
