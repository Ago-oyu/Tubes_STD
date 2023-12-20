#ifndef WISATA_H_INCLUDED
#define WISATA_H_INCLUDED
#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev

typedef struct elmPaketWisata*adrPaket;
typedef struct elmRelasi *adrRelasi;
typedef struct elmWisatawan *adrWisatawan;

struct wisatawan {
    string nama;
    int umur;

};

struct paketWisata {
    string destinasi;
    int harga;

};

struct elmRelasi {
    adrPaket paket;
    adrRelasi next;
};

struct elmWisatawan {
    wisatawan info;
    adrRelasi relasi;
    adrWisatawan prev;
    adrWisatawan next;
};

struct elmPaketWisata {
    paketWisata info;
    adrPaket next;
};

struct listWisatawan {
    adrWisatawan first;
    adrWisatawan last;
};

struct listPaket {
    adrPaket first;
};

void createListWisatawan(listWisatawan &W);
void createListPaket(listPaket &P);
adrWisatawan createElmWisatawan(wisatawan X);
adrPaket createElmPaket(paketWisata X);
#endif // WISATA_H_INCLUDED
