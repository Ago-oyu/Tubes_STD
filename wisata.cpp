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
    first(relasi(Q)) = NULL;
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

void inserLastRelasi(listRelasi &LR, adrRelasi Q){
    if (first(LR) == NULL) {
        first(LR) = Q;
    } else {
        adrRelasi curr = first(LR);
        while (next(curr) != NULL) {
            curr = next(curr);
        }
        next(curr) = Q;
    }
}

adrWisatawan cariWisatawan(listWisatawan &LW, string atasNama) {
    adrWisatawan found = NULL;
    adrWisatawan curr = first(LW);
    while (curr != NULL && found == NULL) {
        if (info(curr).atasNama == atasNama) {
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

void setPaketForWisatawan(listWisatawan &LW, listPaket LP, string atasNama,string destinasi) {
    adrWisatawan pW;
    adrPaket pP;
    adrRelasi pR;

    pW = cariWisatawan(LW, atasNama);
    pP = cariPaket(LP, destinasi);

    if (pW == NULL) {
        cout<<"warning: tidak ada wisatawan atas nama "<<atasNama<<endl<<endl;
    } else if (pP == NULL) {
        cout<<"warning: tidak ada paket wisata dengan destinasi "<<destinasi<<endl<<endl;
    } else {
        pR = new elmRelasi;
        paket(pR) = pP;
        inserLastRelasi(relasi(pW), pR);
    }
}

void clearRelasi(listRelasi &LR) {
    adrRelasi R = first(LR);
    while (R != NULL) {
        first(LR) = next(R);
        next(R) = NULL;
        paket(R) = NULL;
        delete R;
        R = first(LR);
    }
}

void deleteFirstWisatawan(listWisatawan &LW, adrWisatawan Q) {
    Q = first(LW);
    if (first(LW) == last(LW)) {
        first(LW) = next(Q);
        next(Q) = NULL;
        prev(first(LW)) = NULL;
    } else {
        first(LW) = NULL;
        last(LW) = NULL;
    }
}

void deleteWisatawan(listWisatawan &LW, string atasNama) {
    adrWisatawan Q;
    Q = cariWisatawan(LW, atasNama);
    if (Q == NULL) {
        cout<<"warning: tidak ada wisatawan atas nama "<<atasNama<<endl<<endl;
    } else {
        clearRelasi(relasi(Q));
        if (Q == first(LW)) {
            first(LW) = next(Q);

        }
    }
}
