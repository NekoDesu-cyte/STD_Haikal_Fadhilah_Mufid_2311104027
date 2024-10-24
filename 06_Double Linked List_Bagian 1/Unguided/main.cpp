#include "doubleList.h"

address findNopolKendaraan(const List& L, const string& nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

int main () {
    List L;
    createList(L);
    int jumlahKendaraan;
    cout << "Masukan jumlah kendaraan yang ingin ditambahkan : ";
    cin >> jumlahKendaraan;

    for(int i = 0; i < jumlahKendaraan; ++i) {
        string nopol, warna;
        int thnBuat;
        
        

        if (findNopolKendaraan(L, nopol) != nullptr) {
            cout << "Nomor Polisi sudah terdaftar" << endl;
            continue;
        }

        cout << "Masukan Nomor Polisi : ";
        cin >> nopol;
        cout << endl;

        cout << "Masukan Warna Kendaraan : ";
        cin >> warna;
        cout << endl; 

        cout << "Masukan Tahun Kendaraan : ";
        cin >> thnBuat;
        cout << endl;
        
        infotype kendaraan = {nopol, warna, thnBuat};
        address P = alokasi(kendaraan);
        insertLast(L, P);
    }

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    return 0;
}   