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

    W.atasNama= "tes";
    W.jmlDewasa = 18;
    W.jmlAnak = 3;

    P.destinasi = "Bromo";
    P.harga = 1000000;
    P.durasiHari = 4;
    P.durasiMalam = 3;

    insertLastPaket(LP, createElmPaket(P));
    insertLastPaket(LP, createElmPaket(P));
    showAllPaket(LP);

    adrWisatawan pW = createElmWisatawan(W);
    insertLastWisatawan(LW, pW);
    //showAllWisatawan(LW);

    W.atasNama = "tes2";
    W.jmlDewasa = 19;
    W.jmlAnak = 10;

    //pW = createElmWisatawan(W);
    insertLastWisatawan(LW, createElmWisatawan(W));
    showAllWisatawanWithRelation(LW);

    setPaketForWisatawan(LW, LP, "tes2", "Bromo");
    showAllWisatawanWithRelation(LW);
    return 0;
}
