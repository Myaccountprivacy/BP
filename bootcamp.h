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

struct elmSesi {
    infoSesi info;
    adrSesi next;
    adrSesi prev;
};

struct elmBootcamp {
    infoBootcamp info;
    adrBootcamp next;
    adrSesi firstSesi;
};

struct List {
    adrBootcamp first; // Head dari list bootcamp
};

// Membuat List kosong (List Parent)
void createList(List &L);

adrBootcamp createElmBootcamp_103012400164(infoBootcamp data);
adrSesi createElmSesi_103012400164(infoSesi data);
void insertBootcamp_103012400164(List &L, adrBootcamp p);
void addSesiToBootcamp_103012400206(List &L, string judulBootcamp, adrSesi C);
adrBootcamp findBootcamp_103012400164(List L, string judul);
void showSesiByBootcamp_103012400206(List L, string judulBootcamp);
void deleteBootcamp_103012400206(List &L, string judulBootcamp);
void deleteSesi_103012400206(List &L, string judulBootcamp, string namaSesi);
void showAll(List L);
int countSesi_103012400206(List L, string judulBootcamp);
void showMinMaxSesi_103012400164(List L);
void printMenu();

#endif // BOOTCAMP_H_INCLUDED