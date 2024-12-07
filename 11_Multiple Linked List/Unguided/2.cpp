#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Buku {
    string judul;
    string tanggalPengembalian;

    Buku(string judulBuku, string tanggalKembali)
        : judul(judulBuku), tanggalPengembalian(tanggalKembali) {
    }
};

struct Anggota {
    string nama;
    string id;
    list<Buku> bukuDipinjam;

    Anggota(string namaAnggota, string idAnggota)
        : nama(namaAnggota), id(idAnggota) {}
};
void tampilkanData(const list<Anggota>& anggotaList) {
    for (const auto& anggota : anggotaList) {
        cout << "Nama Anggota: " << anggota.nama << " (ID: " << anggota.id << ")\n";
        if (anggota.bukuDipinjam.empty()) {
            cout << "  Tidak ada buku yang dipinjam\n";
        } else {
            for (const auto& buku : anggota.bukuDipinjam) {
                cout << "  Judul Buku: " << buku.judul 
                     << ", Tanggal Pengembalian: " << buku.tanggalPengembalian << "\n";
            }
        }
    }
    cout << endl;
}
void tambahBuku(list<Anggota>& anggotaList, const string& namaAnggota, const Buku& bukuBaru) {
    for (auto& anggota : anggotaList) {
        if (anggota.nama == namaAnggota) {
            anggota.bukuDipinjam.push_back(bukuBaru);
            return;
        }
    }
    cout << "Anggota dengan nama " << namaAnggota << " tidak ditemukan.\n";
}
void hapusAnggota(list<Anggota>& anggotaList, const string& namaAnggota) {
    auto it = anggotaList.begin();
    while (it != anggotaList.end()) {
        if (it->nama == namaAnggota) {
            it = anggotaList.erase(it);
            cout << "Anggota " << namaAnggota << " berhasil dihapus.\n";
            return;
        } else {
            ++it;
        }
    }
    cout << "Anggota dengan nama " << namaAnggota << " tidak ditemukan.\n";
}
int main() {
    list<Anggota> anggotaList = {
        {"Rani", "A001"},
        {"Dito", "A002"},
        {"Vina", "A003"}
    };

    tambahBuku(anggotaList, "Rani", {"Pemrograman C++", "01/12/2024"});
    tambahBuku(anggotaList, "Dito", {"Algoritma Pemrograman", "15/12/2024"});
    tambahBuku(anggotaList, "Rani", {"Struktur Data", "10/12/2024"});

    hapusAnggota(anggotaList, "Dito");

    tampilkanData(anggotaList);

    return 0;
}