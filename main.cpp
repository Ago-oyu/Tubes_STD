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
    adrRelasi pR;
    string atasNama, destinasi;
    int pilihan;

    do {
        cout<<"1. Insert Data"<<endl;
        cout<<"2. Show Data"<<endl;
        cout<<"3. Cari Data"<<endl;
        cout<<"4. Hapus Data"<<endl;
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
            system("cls");
            cout<<"1. Data Wisatawan"<<endl;
            cout<<"2. Data Paket Wisata"<<endl;
            cout<<"3. Data Wisatawan dan Paketnya"<<endl;
            cout<<"Pilih Menu: ";cin>>pilihan;
            switch(pilihan) {
                case 1:
                    showAllWisatawan(LW);
                    break;
                case 2:
                    showAllPaket(LP);
                    break;
                case 3:
                    showAllWisatawanWithRelation(LW);
                    break;
            }
            break;
        case 3:
            system("cls");
            cout<<"1. Cari Data Wisatawan"<<endl;
            cout<<"2. Cari Data Paket Wisata"<<endl;
            cout<<"3. Cari Data Paket pada Wisatawan"<<endl;
            cout<<"Pilih Menu: ";cin>>pilihan;
            switch(pilihan) {
                case 1:
                    cout<<"Wisatawan yang Ingin Dicari: ";cin>>atasNama;
                    pW = cariWisatawan(LW, atasNama);
                    if (pW != NULL) {
                        printWisatawan(pW);
                    }

                    break;
                case 2:
                    cout<<"Paket yang Ingin Dicari: ";cin>>destinasi;
                    pP = cariPaket(LP, destinasi);
                    if (pP == NULL) {
                        printPaket(pP);
                    }
                    break;
                case 3:
                    cout<<"Wisatawan: ";cin>>atasNama;
                    cout<<"Paket Wisata: ";cin>>destinasi;
                    pW = cariWisatawan(LW, atasNama);
                    if (pW != NULL) {
                        pR = cariRelasi(pW, destinasi);
                        if (pR != NULL) {
                            printWisatawanWithRelation(pW);
                        }
                    }
                    break;
            }
            break;
        case 4:
            system("cls");
            cout<<"1. Hapus Data Wisatawan"<<endl;
            cout<<"2. Hapus Data Paket Wisata"<<endl;
            cout<<"3. Hapus Data Paket pada Wisatawan"<<endl;
            cout<<"Pilih Menu: ";cin>>pilihan;
            switch(pilihan) {
                case 1:
                    cout<<"WIsatawan yang Ingin Dihapus: ";cin>>atasNama;
                    deleteWisatawan(LW, atasNama);
                    break;
                case 2:
                    cout<<"Paket Wisata yang Ingin Dihapus: ";cin>>destinasi;
                    deletePaket(LP, LW, destinasi);
                    break;
                case 3:
                    cout<<"Paket Wisata: ";cin>>destinasi;
                    cout<<"Pada Wisatawan: ";cin>>atasNama;
                    deleteRelasi(LW, atasNama, destinasi);
                    break;
            }
            break;
        case 5:
            system("cls");
            setPaketForWisatawan(LW, LP, atasNama, destinasi);
            break;
        case 0:

            break;
    }
    } while (pilihan != 0);
    return 0;
}
