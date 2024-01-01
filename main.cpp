#include<stdlib.h>
#include <iostream>
#include "wisata.h"

int main()
{
    listPaket LP;
    listWisatawan LW;
    createListPaket(LP);
    createListWisatawan(LW);
    wisatawan W;
    adrWisatawan pW;
    paketWisata P;
    adrPaket pP;

    int pilihan;

    do {
        cout<<"1. Insert Data"<<endl;
        cout<<"2. Show Data"<<endl;
        cout<<"3. Find Data"<<endl;
        cout<<"4. Delete Data"<<endl;
        cout<<"5. Connect Data"<<endl;
        cout<<"0. Exit Program"<<endl;
        cout<<"Pilih Menu: ";cin>>pilihan;

    switch(pilihan){
        case 1:
            system("cls");
            cout<<"1. Insert Wisatawan"<<endl;
            cout<<"2. Insert Paket Wisata"<<endl;
            cout<<"Pilih Menu: ";cin>>pilihan;
            switch(pilihan) {
                case 1:
                    system("cls");
                    cout<<"Atas Nama: ";cin>>W.atasNama;
                    while (W.atasNama != "#"){
                        cout<<"Jumlah Dewasa: ";cin>>W.jmlDewasa;
                        cout<<"Jumlah Anak(<12 Tahun): ";cin>>W.jmlAnak;
                        cout<<endl;
                        pW = createElmWisatawan(W);
                        insertLastWisatawan(LW, pW);
                        cout<<"Atas Nama: ";cin>>W.atasNama;
                    }
                    break;
                case 2:
                    system("cls");
                    cout<<"Destinasi: ";cin>>P.destinasi;
                    while (P.destinasi != "#") {
                        cout<<"Harga: ";cin>>P.harga;
                        cout<<"Durasi(Hari): ";cin>>P.durasiHari;
                        cout<<"Durasi(Malamm): ";cin>>P.durasiMalam;
                        cout<<endl;
                        pP = createElmPaket(P);
                        insertLastPaket(LP, pP);
                        cout<<"Destinasi: ";cin>>P.destinasi;
                    }
                    break;
            }
            break;
        case 2:
            showAllWisatawan(LW);
//            cout<<"1. Data Wisatawan"<<endl;
//            cout<<"Pilih Menu: ";cin>>pilihan;

            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 0:
            break;
    }
    } while (pilihan != 0);

//    W.atasNama= "tes";
//    W.jmlDewasa = 18;
//    W.jmlAnak = 3;
//
//    P.destinasi = "Bromo";
//    P.harga = 1000000;
//    P.durasiHari = 4;
//    P.durasiMalam = 3;
//    insertLastPaket(LP, createElmPaket(P));
//    P.destinasi = "Malang";
//    insertLastPaket(LP, createElmPaket(P));
//    showAllPaket(LP);
//
//    adrWisatawan pW = createElmWisatawan(W);
//    insertLastWisatawan(LW, pW);
//    //showAllWisatawan(LW);
//
//    W.atasNama = "tes2";
//    W.jmlDewasa = 19;
//    W.jmlAnak = 10;
//
//    //pW = createElmWisatawan(W);
//    insertLastWisatawan(LW, createElmWisatawan(W));
//    showAllWisatawanWithRelation(LW);
//
//    setPaketForWisatawan(LW, LP, "tes2", "Bromo");
//    setPaketForWisatawan(LW, LP, "tes2", "Malang");
//    showAllWisatawanWithRelation(LW);
    return 0;
}
