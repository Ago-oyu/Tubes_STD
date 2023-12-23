#include "wisata.h"

void createListWisatawan(listWisatawan &LW) {
    first(LW) = NULL;
    last(LW) = NULL;
}

void createListPaket(listPaket &LP) {
    first(LP) = NULL;
}

adrWisatawan createElmWisatawan(wisatawan W) {
    adrWisatawan Q = new elmWisatawan;
    info(Q) = W;
    next(Q) = NULL;
    prev(Q) = NULL;
    relasi(Q) = NULL;
    return Q;
}

adrPaket createElmPaket(paketWisata P) {
    adrPaket Q = new elmPaketWisata;
    info(Q) = P;
    next(Q) = NULL;
    return Q;
}

void insertLastWisatawan(listWisatawan &LW, adrWisatawan Q) {
    if (first(LW) == NULL) {
        first(LW) = Q;
        last(LW) = Q;
    } else {
        next(last(LW)) = Q;
        prev(Q) = last(LW);
        last(LW) = Q;
    }
}

void insertLastPaket(listPaket &LP, adrPaket Q) {
    if (first(LP) == NULL) {
        first(LP) = Q;
    } else {
        adrPaket curr = first(LP);
        while (next(curr) != NULL) {
            curr = next(curr);
        }
        next(curr) = Q;
    }
}

adrWisatawan cariWisatawan(listWisatawan &LW, string nama) {
    adrWisatawan found = NULL;
    adrWisatawan curr = first(LW);
    while (curr != NULL && found == NULL) {
        if (info(curr).atasNama == nama) {
            found = curr;
        }
        curr = next(curr);
    }
    return found;
}

adrPaket cariPaket(listPaket &LP, string destinasi) {
    adrPaket found = NULL;
    adrPaket curr = first(LP);
    while (curr != NULL && found == NULL) {
        if (info(curr).destinasi == destinasi) {
            found = curr;
        }
        curr = next(curr);
    }
    return found;
}

void showAllWisatawan(listWisatawan LW) {
    adrWisatawan curr = first(LW);
    while (curr != NULL) {
        cout<<"Atas Nama: "<<info(curr).atasNama<<endl;
        cout<<"Jumlah Dewasa (>11 Tahun): "<<info(curr).jmlDewasa<<endl;
        cout<<"Jumlah Anak (0-11 Tahun): "<<info(curr).jmlAnak<<endl<<endl;
        curr = next(curr);
    }
}

void showAllPaket(listPaket LP) {
    adrPaket curr = first(LP);
    while (curr != NULL) {
        cout<<"Destinasi: "<<info(curr).destinasi<<endl;
        cout<<"Harga: "<<info(curr).harga<<endl;
        cout<<"Durasi: "<<info(curr).durasiHari<<" Hari "<<info(curr).durasiMalam<<" Malam"<<endl<<endl;
        curr = next(curr);
    }
}

void addPaket(listWisatawan &W, listPaket P, string destinasi) {

}
