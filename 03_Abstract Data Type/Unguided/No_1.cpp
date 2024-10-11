#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string NIM;
    float UTS;
    float UAS;
    float Tugas;
    float nilaiAkhir;

};

float hitungNilaiAkhir (float UTS, float UAS, float Tugas) {
    return (0.3 * UTS) + (0.4 * UAS) + (0.3 * Tugas);
}

int main () {
    Mahasiswa mahasiswa [10] ;

    for (int i = 0; i < 10; i++) {
        cout << "Masukan data Mahasiswa ke " << i + 1 << endl;
        cout << "Nama = ";
        cin.ignore ();
        getline (cin,mahasiswa[i].nama);
        cout << "NIM = ";
        cin >> mahasiswa[i].NIM;
        cout << "Nilai UTS";
        cin >> mahasiswa[i].UTS;
        cout << "Nilai UAS";
        cin >> mahasiswa[i].UAS;
        cout << "Nilai Tugas";
        cin >> mahasiswa[i].Tugas;

        mahasiswa[i].nilaiAkhir = hitungNilaiAkhir(mahasiswa[i].UTS, mahasiswa[i].UAS, mahasiswa[i].Tugas);
        cout << endl;
    }
    cout << "\nData Mahasiswa dan Nilai Akhir =\n";
    for (int i = 0; i < 10; i++) {
        cout << "Mahasiswa ke " << i + 1 << endl;
        cout << "Nama = " << mahasiswa[i].nama << endl;
        cout << "NIM = " << mahasiswa[i].NIM << endl;
        cout << "Nilai UTS = " << mahasiswa[i].UTS << endl;
        cout << "Nilai UAS = " << mahasiswa[i].UAS << endl;
        cout << "Nilai Tugas = " << mahasiswa[i].Tugas << endl;
        cout << "Nilai Akhir = " << mahasiswa[i].nilaiAkhir << endl;
        cout << endl;
    }
    return 0;
}
