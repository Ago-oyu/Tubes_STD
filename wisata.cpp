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

adrRelasi cariRelasi(adrWisatawan W, string destinasi) {
    adrRelasi found = NULL;
    adrRelasi curr = first(relasi(W));
    while (curr != NULL && found == NULL) {
        if (info(paket(curr)).destinasi == destinasi) {
            found = curr;
        }
        curr = next(curr);
    }
    return found;
}

void showAllWisatawan(listWisatawan LW) {
    adrWisatawan curr = first(LW);
    int i = 1;
    while (curr != NULL) {
        cout<<i<<") Atas Nama\t: "<<info(curr).atasNama<<endl;
        cout<<"   Jumlah Dewasa: "<<info(curr).jmlDewasa<<endl;
        cout<<"   Jumlah Anak\t: "<<info(curr).jmlAnak<<endl<<endl;
        curr = next(curr);
        i++;
    }
}

void showAllPaket(listPaket LP) {
    adrPaket curr = first(LP);
    int i = 1;
    while (curr != NULL) {
        cout<<i<<". Destinasi\t: "<<info(curr).destinasi<<endl;
        cout<<"   Harga\t: "<<info(curr).harga<<endl;
        cout<<"   Durasi\t: "<<info(curr).durasiHari<<" Hari "<<info(curr).durasiMalam<<" Malam"<<endl<<endl;
        curr = next(curr);
        i++;
    }
}

void showAllWisatawanWithRelation(listWisatawan LW) {
    adrWisatawan curr = first(LW);
    int i = 1;
    while (curr != NULL) {
        cout<<i<<". Atas Nama\t: "<<info(curr).atasNama<<endl;
        cout<<"   Jumlah Dewasa: "<<info(curr).jmlDewasa<<endl;
        cout<<"   Jumlah Anak\t: "<<info(curr).jmlAnak<<endl;
        cout<<"   Paket Wisata yang dipilih: ";
        adrRelasi R = first(relasi(curr));
        if (R == NULL) {
            cout<<"Kosong"<<endl<<endl;
        } else {
            cout<<endl;
            char x = 'a';
            while (R != NULL) {
                cout<<"\t"<<x<<". "<<info(paket(R)).destinasi<<endl;
                R = next(R);
                x++;
            }
            cout<<endl;
        }
        curr = next(curr);
        i++;
    }
}

void printWisatawan(adrWisatawan Q) {
    cout<<"   Atas Nama\t: "<<info(Q).atasNama<<endl;
    cout<<"   Jumlah Dewasa: "<<info(Q).jmlDewasa<<endl;
    cout<<"   Jumlah Anak\t: "<<info(Q).jmlAnak<<endl;
}

void printPaket(adrPaket Q) {
    cout<<"   Destinasi\t: "<<info(Q).destinasi<<endl;
    cout<<"   Harga\t: "<<info(Q).harga<<endl;
    cout<<"   Durasi\t: "<<info(Q).durasiHari<<" Hari "<<info(Q).durasiMalam<<" Malam"<<endl;
}

void printWisatawanWithRelation(adrWisatawan Q) {
    cout<<"   Atas Nama\t: "<<info(Q).atasNama<<endl;
    cout<<"   Jumlah Dewasa\t: "<<info(Q).jmlDewasa<<endl;
    cout<<"   Jumlah Anak\t: "<<info(Q).jmlAnak<<endl;
    cout<<"   Paket Wisata yang dipilih\t: ";
    adrRelasi R = first(relasi(Q));
    if (R == NULL) {
        cout<<"Kosong"<<endl;
    } else {
        cout<<endl;
        char x = 'a';
        while (R != NULL) {
            cout<<"\t"<<x<<". "<<info(paket(R)).destinasi<<endl;
            R = next(R);
            x++;
        }
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
        next(pR) = NULL;
        inserLastRelasi(relasi(pW), pR);
    }
}

void deleteFirstRelasi(adrWisatawan &W, adrRelasi &R) {
    if (first(relasi(W)) == NULL) {
        cout<<"List Relasi Kosong"<<endl;
    } else {
        R = first(relasi(W));
        first(relasi(W)) = next(R);
        next(R) = NULL;
    }
}

void deleteLastRelasi(adrWisatawan &W, adrRelasi &R) {
    adrRelasi Q = first(relasi(W));
    R = next(Q);
    while (next(R) != NULL) {
        Q = R;
        R = next(R);
    }
    next(Q) = NULL;
}

void deleteAfterRelasi(adrRelasi &prec, adrRelasi &R) {
    R = next(prec);
    next(prec) = next(R);
    next(R) = NULL;
}

void deleteRelasi(listWisatawan &LW, string atasNama, string destinasi) {
    adrWisatawan W;
    W = cariWisatawan(LW, atasNama);
    if (W != NULL) {
        adrRelasi Q;
        Q = cariRelasi(W, destinasi);
        if (Q != NULL) {
            paket(Q) = NULL;
            if (Q == first(relasi(W))) {
                deleteFirstRelasi(W, Q);
            } else if (next(Q) == NULL) {
                deleteLastRelasi(W, Q);
            } else {
                adrRelasi prec = first(relasi(W));
                while (next(prec) != Q) {
                    prec = next(prec);
                }
                deleteAfterRelasi(prec, Q);
            }
        } else {
            cout<<"NOTE: Wisatawan tidak memilih paket "<<destinasi<<endl;
        }

    } else {
        cout<<"NOTE: Tidak ada wisatawan atas nama "<<atasNama<<endl;
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

void deleteFirstWisatawan(listWisatawan &LW, adrWisatawan &Q) {
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

void deleteLastWisatawan(listWisatawan &LW, adrWisatawan &Q) {
    Q = last(LW);
    last(LW) = prev(last(LW));
    prev(Q) = NULL;
    next(last(LW)) = NULL;
}

void deleteAfterWisatawan(adrWisatawan prec, adrWisatawan &Q) {
    Q = next(prec);
    next(prec) = next(Q);
    prev(next(Q)) = prec;
    prev(Q) = NULL;
    next(Q) = NULL;
}

void deleteWisatawan(listWisatawan &LW, string atasNama) {
    adrWisatawan Q;
    Q = cariWisatawan(LW, atasNama);
    if (Q == NULL) {
        cout<<"NOTE: Tidak ada wisatawan atas nama "<<atasNama<<endl;
    } else {
        clearRelasi(relasi(Q));
        if (Q == first(LW)) {
            deleteFirstWisatawan(LW,Q);
        } else if (Q == last(LW)) {
            deleteLastWisatawan(LW, Q);
        } else {
            adrWisatawan prec = prev(Q);
            deleteAfterWisatawan(prec, Q);
        }
    }
}

void deleteFirstPaket(listPaket &LP, adrPaket &Q) {
    if (first(LP) == NULL) {
        cout<<"List Paket Kosong"<<endl;
    } else {
        Q = first(LP);
        first(LP) = next(Q);
        next(Q) = NULL;
    }
}

void deleteLastPaket(listPaket &LP, adrPaket &Q) {
    adrPaket R = first(LP);
    Q = next(R);
    while (next(Q) != NULL) {
        R = Q;
        Q = next(Q);
    }
    next(R) = NULL;
}

void deleteAfterPaket(listPaket &LP, adrPaket &prec, adrPaket &Q) {
    Q = next(prec);
    next(prec) = next(Q);
    next(Q) = NULL;
}

void deletePaket(listPaket &LP, listWisatawan &LW, string destinasi) {
    adrPaket Q;
    Q = cariPaket(LP, destinasi);
    if (Q == NULL) {
        cout<<"Note: Tidak ada paket dengan destinasi "<<destinasi<<endl;
    } else {
        adrWisatawan R = first(LW);
        while (R != NULL) {
            deleteRelasi(LW, info(R).atasNama, destinasi);
            R = next(R);
        }
        if (Q == first(LP)) {
            deleteFirstPaket(LP, Q);
        } else if (next(Q) == NULL) {
            deleteLastPaket(LP, Q);
        } else {
            adrPaket prec = first(LP);
            while (next(prec) != Q) {
                prec = next(prec);
            }
            deleteAfterPaket(LP, prec, Q);
        }
    }
}
