#ifndef WISATA_H_INCLUDED
#define WISATA_H_INCLUDED
#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define relasi(P) P->relasi
#define paket(P) P->paket

typedef struct elmPaketWisata*adrPaket;
typedef struct elmRelasi *adrRelasi;
typedef struct elmWisatawan *adrWisatawan;

struct wisatawan {
    string atasNama;
    int jmlDewasa;
    int jmlAnak;
};

struct paketWisata {
    string destinasi;
    int harga;
    int durasiHari;
    int durasiMalam;
};

struct elmRelasi {
    adrPaket paket;
    adrRelasi next;
};

struct listRelasi {
    adrRelasi first;
};

struct elmWisatawan {
    wisatawan info;
    listRelasi relasi;
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

void createListWisatawan(listWisatawan &LW);
void createListPaket(listPaket &LP);
adrWisatawan createElmWisatawan(wisatawan W);
adrPaket createElmPaket(paketWisata P);
void insertLastWisatawan(listWisatawan &LW, adrWisatawan Q);
void insertLastPaket(listPaket &LP, adrPaket Q);
void inserLastRelasi(listRelasi &LR, adrRelasi Q);
adrWisatawan cariWisatawan(listWisatawan &LW, string nama);
adrPaket cariPaket(listPaket &LP, string destinasi);
adrRelasi cariRelasi(adrWisatawan W, string destinasi);
void showAllWisatawan(listWisatawan LW);
void showAllPaket(listPaket LP);
void showAllWisatawanWithRelation(listWisatawan LW);
void printWisatawan(adrWisatawan Q);
void printPaket(adrPaket Q);
void printWisatawanWithRelation(adrWisatawan Q);
void setPaketForWisatawan(listWisatawan &LW, listPaket LP, string atasNama,string destinasi);
void deleteFirstRelasi(adrWisatawan &W, adrRelasi &R);
void deleteLastRelasi(adrWisatawan &W, adrRelasi &R);
void deleteAfterRelasi(adrRelasi &prec, adrRelasi &R);
void deleteRelasi(listWisatawan &LW, string atasNama, string destinasi);
void clearRelasi(listRelasi &LR);
void deleteFirstWisatawan(listWisatawan &LW, adrWisatawan &Q);
void deleteLastWisatawan(listWisatawan &LW, adrWisatawan &Q);
void deleteAfterWisatawan(adrWisatawan prec, adrWisatawan &Q);
void deleteWisatawan(listWisatawan &LW, string atasNama);
void deleteFirstPaket(listPaket &LP, adrPaket &Q);
void deleteLastPaket(listPaket &LP, adrPaket &Q);
void deleteAfterPaket(listPaket &LP, adrPaket &prec, adrPaket &Q);
void deletePaket(listPaket &LP, listWisatawan &LW, string destinasi);

#endif // WISATA_H_INCLUDED
