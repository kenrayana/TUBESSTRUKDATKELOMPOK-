#include <iostream>
#include <string>

#include "songlibrary.h"
#include "admin.h"
#include "playlist.h"
#include "player.h"

using namespace std;

// =====================================================
// MENU ADMIN
// =====================================================
void menuAdmin(SongLibrary &lib, Admin &admin) {
    int pilih;

    do {
        cout << "\n===== MENU ADMIN =====\n";
        cout << "1. Tambah Lagu\n";
        cout << "2. Lihat Semua Lagu\n";
        cout << "3. Update Lagu\n";
        cout << "4. Hapus Lagu\n";
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cin.ignore();
            string judul, penyanyi, genre, reff, durasi;

            cout << "Judul    : "; getline(cin, judul);
            cout << "Penyanyi : "; getline(cin, penyanyi);
            cout << "Genre    : "; getline(cin, genre);
            cout << "Durasi   : "; getline(cin, durasi);
            cout << "Reff     : "; getline(cin, reff);

            lib.addSong(judul, penyanyi, genre, durasi, reff);
            cout << "Lagu berhasil ditambahkan.\n";
        }

        else if (pilih == 2) {
            lib.showLibrary();
        }

        else if (pilih == 3) {
            int id;
            cin.ignore();
            cout << "ID Lagu: ";
            cin >> id;
            cin.ignore();

            string judul, penyanyi, genre, reff, durasi;
            cout << "Judul baru    : "; getline(cin, judul);
            cout << "Penyanyi baru : "; getline(cin, penyanyi);
            cout << "Genre baru    : "; getline(cin, genre);
            cout << "Durasi baru   : "; getline(cin, durasi);
            cout << "Reff baru     : "; getline(cin, reff);

            if (lib.updateSong(id, judul, penyanyi, genre, durasi, reff))
                cout << "Update berhasil.\n";
            else
                cout << "ID lagu tidak ditemukan.\n";
        }

        else if (pilih == 4) {
            int id;
            cout << "ID Lagu: ";
            cin >> id;

            if (lib.deleteSong(id, admin))
                cout << "Lagu berhasil dihapus.\n";
            else
                cout << "ID lagu tidak ditemukan.\n";
        }

    } while (pilih != 0);
}

// =====================================================
// MENU USER
// =====================================================
void menuUser(Admin &admin, SongLibrary &lib) {
    string username;
    cout << "Masukkan username: ";
    cin >> username;

    UserNode* u = findUser(admin, username);
    if (!u) {
        cout << "User tidak ditemukan.\n";
        return;
    }

    if (!u->player)
        u->player = new Player();

    int pilih;
    do {
        cout << "\n===== MENU USER =====\n";
        cout << "1. Buat Playlist\n";
        cout << "2. Lihat Playlist\n";
        cout << "3. Tambah Lagu ke Playlist\n";
        cout << "4. Play Lagu dari Playlist\n";
        cout << "5. Play Lagu dari Library\n";
        cout << "6. Next Lagu (Library)\n";
        cout << "7. Previous Lagu (Library)\n";
        cout << "8. Stop\n";
        cout << "9. Next Lagu dari Playlist\n";
        cout << "10. Previous Lagu dari Playlist\n";
        cout << "11. Hapus Lagu dari Playlist\n";
        cout << "0. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            string nama;
            cin.ignore();
            cout << "Nama playlist: ";
            getline(cin, nama);
            addPlaylist(u, nama);
        }

        else if (pilih == 2) {
            showAllPlaylists(u);
            Playlist* pl = choosePlaylist(u);
            if (pl) showPlaylist(pl);
        }

        else if (pilih == 3) {
            Playlist* pl = choosePlaylist(u);
            if (!pl) continue;

            int id;
            cout << "ID lagu: ";
            cin >> id;

            SongNode* song = lib.findSongByID(id);
            if (!song)
                cout << "Lagu tidak ditemukan.\n";
            else
                addSongToPlaylist(pl, song);
        }

        else if (pilih == 4) {
            Playlist* pl = choosePlaylist(u);
            if (!pl) continue;

            int index;
            cout << "Index lagu: ";
            cin >> index;

            playFromPlaylist(*u->player, pl, index);
        }

        else if (pilih == 5) {
            int id;
            cout << "ID lagu: ";
            cin >> id;
            playFromLibrary(*u->player, lib, id);
        }

        else if (pilih == 6) {
            nextSongLibrary(*u->player);
        }

        else if (pilih == 7) {
            previousSongLibrary(*u->player);
        }

        else if (pilih == 8) {
            stopSong(*u->player);
        }

        else if (pilih == 9) {
            nextSongPlaylist(*u->player);
        }

        else if (pilih == 10) {
            previousSongPlaylist(*u->player);
        }

        else if (pilih == 11) {
            Playlist* pl = choosePlaylist(u);
            if (!pl) continue;

            int id;
            cout << "ID lagu yang dihapus: ";
            cin >> id;

            if (removeSongFromPlaylist(pl, id))
                cout << "Lagu berhasil dihapus dari playlist.\n";
            else
                cout << "Lagu tidak ditemukan di playlist.\n";
        }

    } while (pilih != 0);
}


// =====================================================
// MAIN
// =====================================================
int main() {
    SongLibrary lib;
    Admin admin;
    initAdmin(admin);

    seedDefaultSongs(lib);

    int pilih;
    do {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "3. Tambah User\n";
        cout << "0. Exit\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            menuAdmin(lib, admin);
        }
        else if (pilih == 2) {
            menuUser(admin, lib);
        }
        else if (pilih == 3) {
            string name;
            cout << "Username baru: ";
            cin >> name;
            addUser(admin, name);
        }

    } while (pilih != 0);

    return 0;
}
