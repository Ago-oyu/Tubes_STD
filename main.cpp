#include <iostream>
#include "wisata.h"

int main()
{
    listPaket LP;
    listWisatawan LW;
    wisatawan W;
    adrWisatawan pW;
    paketWisata P;
    adrPaket pP;
    adrRelasi pR;
    string atasNama, destinasi;
    int pilihan;

    createListPaket(LP);
    createListWisatawan(LW);


    cout<<"========== SISTEM DATA PERJALANAN WISATA =========="<<endl;
    do {
        cout<<"(1) Insert Data"<<endl;
        cout<<"(2) Show Data"<<endl;
        cout<<"(3) Cari Data"<<endl;
        cout<<"(4) Hapus Data"<<endl;
        cout<<"(5) Connect Data"<<endl;
        cout<<"(0) Exit Program"<<endl;
        cout<<"Pilih Menu: ";cin>>pilihan;

    switch(pilihan){
        case 1:
            cout<<"\n(1) Insert Wisatawan"<<endl;
            cout<<"(2) Insert Paket Wisata"<<endl;
            cout<<"Pilih Menu: ";cin>>pilihan;
            switch(pilihan) {
                case 1:
                    cout<<"\nAtas Nama: ";cin>>W.atasNama;
                    while (W.atasNama != "#"){
                        cout<<"Jumlah Dewasa: ";cin>>W.jmlDewasa;
                        cout<<"Jumlah Anak(<12 Tahun): ";cin>>W.jmlAnak;
                        pW = createElmWisatawan(W);
                        insertLastWisatawan(LW, pW);
                        cout<<"\nAtas Nama: ";cin>>W.atasNama;
                    }
                    cout<<endl;
                    break;
                case 2:
                    cout<<"\nDestinasi: ";cin>>P.destinasi;
                    while (P.destinasi != "#") {
                        cout<<"Harga: ";cin>>P.harga;
                        cout<<"Durasi(Hari): ";cin>>P.durasiHari;
                        cout<<"Durasi(Malamm): ";cin>>P.durasiMalam;
                        pP = createElmPaket(P);
                        insertLastPaket(LP, pP);
                        cout<<"\nDestinasi: ";cin>>P.destinasi;
                    }
                    cout<<endl;
                    break;
            }
            break;
        case 2:
            cout<<"\n(1) Data Wisatawan"<<endl;
            cout<<"(2) Data Paket Wisata"<<endl;
            cout<<"(3) Data Wisatawan dan Paketnya"<<endl;
            cout<<"(4) Paket Wisata Paling Diminati"<<endl;
            cout<<"Pilih Menu: ";cin>>pilihan;cout<<endl;
            switch(pilihan) {
                case 1:
                    if (first(LW) == NULL) {
                        cout<<"NOTE: List Wisatawan Kosong"<<endl<<endl;
                    } else {
                        showAllWisatawan(LW);
                    }
                    break;
                case 2:
                    showAllPaket(LP);
                    break;
                case 3:
                    showAllWisatawanWithRelation(LW);
                    break;
                case 4:
                    showFavoritPaket(LW, LP);
                    break;
            }
            break;
        case 3:
            cout<<"\n(1) Cari Data Wisatawan"<<endl;
            cout<<"(2) Cari Data Paket Wisata"<<endl;
            cout<<"(3) Cari Data Paket pada Wisatawan"<<endl;
            cout<<"Pilih Menu: ";cin>>pilihan;
            switch(pilihan) {
                case 1:
                    cout<<"\nWisatawan yang Ingin Dicari: ";cin>>atasNama;
                    pW = cariWisatawan(LW, atasNama);
                    if (pW != NULL) {
                        printWisatawan(pW);
                        cout<<"NOTE: Data berhasil ditemukan"<<endl<<endl;
                    } else {
                        cout<<"NOTE: Data wisatawan tidak ditemukan"<<endl<<endl;
                    }
                    break;
                case 2:
                    cout<<"\nPaket yang Ingin Dicari: ";cin>>destinasi;
                    pP = cariPaket(LP, destinasi);
                    if (pP != NULL) {
                        printPaket(pP);
                        cout<<"NOTE: Data berhasil ditemukan"<<endl<<endl;
                    } else {
                        cout<<"NOTE: Data paket wisata tidak ditemukan"<<endl<<endl;
                    }
                    break;
                case 3:
                    cout<<"\nWisatawan: ";cin>>atasNama;
                    pW = cariWisatawan(LW, atasNama);
                    if (pW != NULL) {
                        cout<<"Paket Wisata: ";cin>>destinasi;
                        pR = cariRelasi(pW, destinasi);
                        if (pR != NULL) {
                            printWisatawanWithRelation(pW);
                            cout<<"NOTE: Data berhasil ditemukan"<<endl<<endl;
                        } else {
                            cout<<"NOTE: Wisatawan tidak memilih paket "<<destinasi<<endl<<endl;
                        }
                    } else {
                        cout<<"NOTE: Data wisatawan tidak ditemukan"<<endl<<endl;
                    }
                    break;
            }
            break;
        case 4:
            cout<<"\n(1) Hapus Data Wisatawan"<<endl;
            cout<<"(2) Hapus Data Paket Wisata"<<endl;
            cout<<"(3) Hapus Data Paket pada Wisatawan"<<endl;
            cout<<"Pilih Menu: ";cin>>pilihan;cout<<endl;
            switch(pilihan) {
                case 1:
                    cout<<"Wisatawan yang Ingin Dihapus: ";cin>>atasNama;
                    deleteWisatawan(LW, atasNama);
                    cout<<endl;
                    break;
                case 2:
                    cout<<"Paket Wisata yang Ingin Dihapus: ";cin>>destinasi;
                    deletePaket(LP, LW, destinasi);
                    cout<<endl;
                    break;
                case 3:
                    cout<<"Paket Wisata: ";cin>>destinasi;
                    cout<<"Pada Wisatawan: ";cin>>atasNama;
                    deleteRelasi(LW, atasNama, destinasi);
                    cout<<endl;
                    break;
            }
            break;
        case 5:
            cout<<"\nConnect Wisatawan Atas Nama: ";cin>>atasNama;
            do {
                cout<<"Dengan Paket Wisata: ";cin>>destinasi;
                do {
                    setPaketForWisatawan(LW, LP, atasNama, destinasi);
                    cout<<"Dengan Paket Wisata: ";cin>>destinasi;
                } while (destinasi != "#");
                cout<<"\nConnect Wisatawan Atas Nama: ";cin>>atasNama;
            } while (atasNama != "#");
            cout<<endl;
            break;
        case 0:
            break;
    }
    } while (pilihan != 0);
    return 0;
}
