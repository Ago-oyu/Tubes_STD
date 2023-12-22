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
    showAllWisatawan(LW);

    return 0;
}
