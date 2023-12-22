#include <iostream>
#include "wisata.h"

int main()
{
    listPaket LP;
    listWisatawan LW;
    createListPaket(LP);
    createListWisatawan(LW);
    wisatawan W;
    paketWisata P;

    W.nama = "tes";
    W.umur = 18;
    W.banyakOrang = 3;

    adrWisatawan pW = createElmWisatawan(W);
    insertLastWisatawan(LW, pW);
    //showAllWisatawan(LW);

    W.nama = "tes2";
    W.umur = 19;
    W.banyakOrang = 100;

    //pW = createElmWisatawan(W);
    insertLastWisatawan(LW, createElmWisatawan(W));
    showAllWisatawan(LW);

    return 0;
}
