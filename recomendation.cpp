#include "recomendation.h"
#include <iostream>
using namespace std;

Playlist* generateRecommendation(SongLibrary &lib, GenreOrder &pref) {

    Playlist* rec = new Playlist("Rekomendasi Genre");

    SongNode* current = lib.head;

    while (current != nullptr) {

        // lagu dimasukkan sesuai genre preference
        int priority = pref.getPriority(current->data.genre);

        // skip jika genre tidak ada di preferensi
        if (priority == 999) {
            current = current->next;
            continue;
        }

        // masukkan lagu ke playlist rekomendasi
        addSongToPlaylist(rec, current);

        current = current->next;
    }

    return rec;
}

