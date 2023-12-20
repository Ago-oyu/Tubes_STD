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
    return Q;
}

adrPaket createElmPaket(paketWisata X) {
    adrPaket Q = new elmPaketWisata;
    info(Q) = X;
    next(Q) = NULL;
    return Q;
}

void insertLastWisatawan(listWisatawan &W, adrWisatawan Q) {

}

void insertLastPaket(listPaket &P, adrPaket Q) {

}
