#ifndef WISATA_H_INCLUDED
#define WISATA_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct paketWisata *adrPaket;
typedef struct elmRelasi *adrRelasi;
typedef struct wisatawan *adrWisatawan;

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
    listRelasi relasi;
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

struct listRelasi {
    adrRelasi first;
};

#endif // WISATA_H_INCLUDED
