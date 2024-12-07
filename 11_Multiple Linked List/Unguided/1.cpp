#include <iostream>
#include <string>
#include <list>
using namespace std;

struct Proyek {
    string nama;
    int durasi;

    Proyek(string namaProyek, int durasiProyek) : nama(namaProyek), durasi(durasiProyek) {}
};

struct Pegawai {
    string nama;
    string id;
    list<Proyek> proyekList;

    Pegawai(string namaPegawai, string idPegawai) : nama(namaPegawai), id(idPegawai) {}
};

void tampilkanData(const list<Pegawai>& pegawaiData) {
    for (const auto& pegawai : pegawaiData) {
        cout << "Nama Pegawai: " << pegawai.nama << " (ID: " << pegawai.id << ")\n";
        if (pegawai.proyekList.empty()) {
            cout << "  Tidak ada proyek yang dikelola\n";
        } else {
            for (const auto& proyek : pegawai.proyekList) {
                cout << "  Nama Proyek: " << proyek.nama << ", Durasi: " << proyek.durasi << " bulan\n";
            }
        }
    }
    cout << endl;
}

void tambahProyek(list<Pegawai>& pegawaiData, const string& namaPegawai, const Proyek& proyekBaru) {
    for (auto& pegawai : pegawaiData) {
        if (pegawai.nama == namaPegawai) {
            pegawai.proyekList.push_back(proyekBaru);
            return;
        }
    }
    cout << "Pegawai dengan nama " << namaPegawai << " tidak ditemukan.\n";
}

void hapusProyek(list<Pegawai>& pegawaiData, const string& namaPegawai, const string& namaProyek) {
    for (auto& pegawai : pegawaiData) {
        if (pegawai.nama == namaPegawai) {
            auto it = pegawai.proyekList.begin();
            while (it != pegawai.proyekList.end()) {
                if (it->nama == namaProyek) {
                    it = pegawai.proyekList.erase(it);
                    cout << "Proyek \"" << namaProyek << "\" dihapus dari pegawai " << namaPegawai << ".\n";
                    return;
                } else {
                    ++it;
                }
            }
            cout << "Proyek \"" << namaProyek << "\" tidak ditemukan untuk pegawai " << namaPegawai << ".\n";
            return;
        }
    }
    cout << "Pegawai dengan nama " << namaPegawai << " tidak ditemukan.\n";
}

int main() {
    list<Pegawai> pegawaiData = {
        {"Andi", "P001"},
        {"Budi", "P002"},
        {"Citra", "P003"}
    };

    tambahProyek(pegawaiData, "Andi", {"Aplikasi Mobile", 12});
    tambahProyek(pegawaiData, "Budi", {"Sistem Akuntansi", 8});
    tambahProyek(pegawaiData, "Citra", {"E-commerce", 10});
    tambahProyek(pegawaiData, "Andi", {"Analisis Data", 6});
    hapusProyek(pegawaiData, "Andi", "Aplikasi Mobile");
    tampilkanData(pegawaiData);

    return 0;
}
