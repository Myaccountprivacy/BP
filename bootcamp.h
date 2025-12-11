#ifndef BOOTCAMP_H_INCLUDED
#define BOOTCAMP_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

// Pointer ke alamat memori
typedef struct elmBootcamp* adrBootcamp;
typedef struct elmSesi* adrSesi;

// Tipe data info (Isi data)
struct infoBootcamp {
    string judul;
    string penulis;    // atau penyelenggara
    string kategori;   // misal: Web, Mobile, Data
};


struct infoSesi {
    string namaSesi;
    int durasi;        // dalam jam
    string kesulitan;  // Beginner, Intermediate, Advanced
};


// CHILD: Sesi Pelatihan (Doubly Linked List)
struct elmSesi {
    infoSesi info;
    adrSesi next;
    adrSesi prev;  // Pointer ke elemen sebelumnya (karena DLL)
};

// PARENT: Bootcamp (Singly Linked List)
struct elmBootcamp {
    infoBootcamp info;
    adrBootcamp next;     // Pointer ke bootcamp berikutnya
    adrSesi firstSesi;    // POINTER RELASI: Menunjuk ke sesi pertama (Child)
};

// LIST: Pengelola Utama
struct List {
    adrBootcamp first; // Head dari list bootcamp
};



// Membuat List kosong (List Parent)
void createList(List &L);

// Membuat elemen baru (Alokasi memori)
adrBootcamp createElmBootcamp_103012400164(infoBootcamp data);
adrSesi createElmSesi_103012400164(infoSesi data);

// (a) Menambahkan bootcamp (Insert Parent)
void insertBootcamp_103012400164(List &L, adrBootcamp p);

// (b) & (d) Menambahkan sesi ke bootcamp tertentu
void addSesiToBootcamp_103012400206(List &L, string judulBootcamp, adrSesi C);

// (c) Mencari bootcamp tertentu berdasarkan judul
adrBootcamp findBootcamp_103012400164(List L, string judul);

// (e) Menampilkan sesi berdasarkan bootcamp tertentu
void showSesiByBootcamp_103012400164(List L, string judulBootcamp);

// (f) Menghapus bootcamp beserta seluruh sesinya
// Hati-hati: Harus hapus semua anak dulu baru bapaknya
void deleteBootcamp_103012400206(List &L, string judulBootcamp);

// (g) Menghapus sesi tertentu dari bootcamp tertentu
void deleteSesi_103012400206(List &L, string judulBootcamp, string namaSesi);

// (h) Menampilkan seluruh bootcamp beserta sesinya
void showAll(List L);

// (i) Menghitung jumlah sesi dalam bootcamp tertentu
int countSesi_103012400164(List L, string judulBootcamp);

// (j) Menampilkan bootcamp dengan sesi terbanyak dan paling sedikit
void showMinMaxSesi_103012400164(List L);

// Helper untuk menu (k)
void printMenu();

#endif // BOOTCAMP_H_INCLUDED