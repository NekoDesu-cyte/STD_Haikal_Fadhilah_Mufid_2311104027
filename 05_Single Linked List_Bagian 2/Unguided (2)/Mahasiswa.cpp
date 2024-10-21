#include <iostream>
#include <string>

using namespace std;

struct mahasiswa {
    int NIM;
    string nama;
    mahasiswa* next;

};

struct List {
    mahasiswa* head;
};

void createList(List& L){
    L.head = nullptr;
}

void insertMahasiswa(List& L,int NIM, const string& nama){
    mahasiswa* newNode = new mahasiswa;
    newNode->NIM = NIM;
    newNode->nama = nama;
    newNode->next = nullptr;

    if (L.head == nullptr) {
        L.head = newNode;
    }else
    {
        mahasiswa* temp = L.head;
        while (temp->next != nullptr){
            temp = temp->next;

        }
        temp->next = newNode;
    }
}

mahasiswa* findMahasiswa(List& L, int NIM) {
    mahasiswa* current = L.head;
    while (current != nullptr) {
        if (current->NIM == NIM) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void printAllMahasiswa(List& L) {
    mahasiswa* current = L.head;
    while (current != nullptr) {
        cout << "NIM : " << current->NIM << ", Nama : " << current->nama << endl;
        current = current->next;
    }
}

int main() {
    List mahasiswaList;
    createList(mahasiswaList);

    insertMahasiswa(mahasiswaList, 13, "Hafizh");
    insertMahasiswa(mahasiswaList, 27, "Haikal");
    insertMahasiswa(mahasiswaList, 28, "Gesa");

    printAllMahasiswa(mahasiswaList);

    int NIMToFind;
    cout << "Masukan NIM Mahasiswa yang dicari : ";
    cin >> NIMToFind;

    mahasiswa* foundMahasiswa = findMahasiswa(mahasiswaList, NIMToFind);
    if (foundMahasiswa != nullptr) {
        cout << "Mahasiswa Ditemukan : " << foundMahasiswa->nama << endl;
    
    } else 
    {
        cout << "Mahasiwa dengan NIM " << NIMToFind << " Tidak ditemukan." << endl;
    }

    return 0;
}