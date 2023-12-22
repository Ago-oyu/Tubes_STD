#include "wisata.h"

void createListWisatawan(listWisatawan &W) {
    first(W) = NULL;
    last(W) = NULL;
}

void createListPaket(listPaket &P) {
    first(P) = NULL;
}

adrWisatawan createElmWisatawan(wisatawan X) {
    adrWisatawan Q = new elmWisatawan;
    info(Q) = X;
    next(Q) = NULL;
    prev(Q) = NULL;
    relasi(Q) = NULL;
    return Q;
}

adrPaket createElmPaket(paketWisata X) {
    adrPaket Q = new elmPaketWisata;
    info(Q) = X;
    next(Q) = NULL;
    return Q;
}

void insertLastWisatawan(listWisatawan &W, adrWisatawan Q) {
    if (first(W) == NULL) {
        first(W) = Q;
        last(W) = Q;
    } else {
        next(last(W)) = Q;
        prev(Q) = last(W);
        last(W) = Q;
    }
}

void insertLastPaket(listPaket &P, adrPaket Q) {
    if (first(P) == NULL) {
        first(P) = Q;
    } else {
        adrPaket curr = first(P);
        while (next(curr) != NULL) {
            curr = next(curr);
        }
        next(curr) = Q;
    }
}

adrWisatawan cariWisatawan(listWisatawan &W, string nama) {
    adrWisatawan found = NULL;
    adrWisatawan curr = first(W);
    while (curr != NULL && found == NULL) {
        if (info(curr).atasNama == nama) {
            found = curr;
        }
        curr = next(curr);
    }
    return found;
}

adrPaket cariPaket(listPaket &P, string destinasi) {
    adrPaket found = NULL;
    adrPaket curr = first(P);
    while (curr != NULL && found == NULL) {
        if (info(curr).destinasi == destinasi) {
            found = curr;
        }
        curr = next(curr);
    }
    return found;
}

void showAllWisatawan(listWisatawan W) {
    adrWisatawan curr = first(W);
    while (curr != NULL) {
        cout<<"Atas Nama: "<<info(curr).atasNama<<endl;
        cout<<"Jumlah Dewasa (>11 Tahun): "<<info(curr).jmlDewasa<<endl;
        cout<<"Jumlah Anak (0-11 Tahun): "<<info(curr).jmlAnak<<endl<<endl;
        curr = next(curr);
    }
}

void showAllPaket(listPaket P) {
    adrPaket curr = first(P);
    while (curr != NULL) {
        cout<<"Destinasi: "<<info(curr).destinasi<<endl;
        cout<<"Harga: "<<info(curr).harga<<endl;
        cout<<"Durasi: "<<info(curr).durasiHari<<" Hari "<<info(curr).durasiMalam<<" Malam"<<endl<<endl;
        curr = next(curr);
    }
}

