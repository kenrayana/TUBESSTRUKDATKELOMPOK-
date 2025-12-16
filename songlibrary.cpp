#include "songlibrary.h"
#include "admin.h"
#include <iostream>

using namespace std;

SongLibrary::SongLibrary() {
    head = tail = nullptr;
    autoID = 1;
}

// ADD
void SongLibrary::addSong(
    string title,
    string artist,
    string genre,
    string duration,
    string lyric
) {
    SongNode* newSong = new SongNode(
        autoID++, title, artist, genre, duration, lyric
    );

    if (!head) {
        head = tail = newSong;
    } else {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }
}

// SHOW
void SongLibrary::showLibrary() {
    if (!head) {
        cout << "Library kosong.\n";
        return;
    }

    SongNode* cur = head;
    cout << "\n=== DAFTAR LAGU ===\n";
    while (cur) {
        cout << "[" << cur->id << "] "
             << cur->title << " - "
             << cur->artist << " | "
             << cur->genre << " | "
             << "Durasi: " << cur->duration << endl;
        cur = cur->next;
    }
}

// FIND
SongNode* SongLibrary::findSongByID(int id) {
    SongNode* cur = head;
    while (cur) {
        if (cur->id == id) return cur;
        cur = cur->next;
    }
    return nullptr;
}

// UPDATE
bool SongLibrary::updateSong(
    int id,
    string title,
    string artist,
    string genre,
    string duration,
    string lyric
) {
    SongNode* song = findSongByID(id);
    if (!song) return false;

    song->title = title;
    song->artist = artist;
    song->genre = genre;
    song->duration = duration;
    song->lyric = lyric;
    return true;
}

// DELETE
bool SongLibrary::deleteSong(int id, Admin& admin) {
    SongNode* song = findSongByID(id);
    if (!song) return false;

    // 🔥 HAPUS DARI SEMUA PLAYLIST
    removeSongFromAllPlaylists(admin.firstUser, id);

    if (song == head) head = song->next;
    if (song == tail) tail = song->prev;
    if (song->prev) song->prev->next = song->next;
    if (song->next) song->next->prev = song->prev;

    delete song;
    return true;
}

// SEED

void seedDefaultSongs(SongLibrary& lib) {
    // POP
    lib.addSong("Blue", "YOASOBI", "Pop", "3:15",
        "I won't forget the days we laughed together...");
    lib.addSong("Akad", "Payung Teduh", "Pop", "4:10",
        "Bila nanti saatnya t'lah tiba...");
    lib.addSong("Hati-Hati di Jalan", "Tulus", "Pop", "4:05",
        "Kita berjalan menyusuri...");

    // JAZZ
    lib.addSong("Fly Me To The Moon", "Frank Sinatra", "Jazz", "2:30",
        "Fly me to the moon...");
    lib.addSong("What A Wonderful World", "Louis Armstrong", "Jazz", "2:20",
        "I see trees of green...");
    lib.addSong("Autumn Leaves", "Eva Cassidy", "Jazz", "4:45",
        "The falling leaves drift by...");

    // ROCK
    lib.addSong("Fix You", "Coldplay", "Rock", "4:55",
        "Lights will guide you home...");
    lib.addSong("Bohemian Rhapsody", "Queen", "Rock", "5:55",
        "Is this the real life...");
    lib.addSong("Smells Like Teen Spirit", "Nirvana", "Rock", "5:01",
        "Load up on guns...");

    // DJ / EDM
    lib.addSong("Faded", "Alan Walker", "DJ", "3:32",
        "Where are you now...");
}
