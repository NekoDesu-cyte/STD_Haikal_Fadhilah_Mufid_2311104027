#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    Mahasiswa* next;
};

struct Queue {
    Mahasiswa* head;
    Mahasiswa* tail;
};

void createQueue(Queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmptyQueue(Queue &Q) {
    return Q.head == nullptr;
}

void enqueue(Queue &Q, string nama, int nim) {
    Mahasiswa* newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmptyQueue(Q)) {
        Q.head = newNode;
        Q.tail = newNode;
    } else {
        // Sisipkan berdasarkan prioritas NIM
        if (nim < Q.head->nim) {
            newNode->next = Q.head;
            Q.head = newNode;
        } else {
            Mahasiswa* temp = Q.head;
            while (temp->next != nullptr && temp->next->nim < nim) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            if (newNode->next == nullptr) {
                Q.tail = newNode;
            }
        }
    }
    cout << "Mahasiswa " << nama << " dengan NIM " << nim << " ditambahkan ke antrian." << endl;
}

void dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrian kosong!" << endl;
    } else {
        Mahasiswa* temp = Q.head;
        cout << "Mahasiswa " << temp->nama << " dengan NIM " << temp->nim << " dikeluarkan dari antrian." << endl;
        Q.head = Q.head->next;
        delete temp;
        if (Q.head == nullptr) {
            Q.tail = nullptr;
        }
    }
}

void viewQueue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrian kosong!" << endl;
    } else {
        Mahasiswa* temp = Q.head;
        cout << "Data antrian mahasiswa (prioritas NIM terkecil):" << endl;
        while (temp != nullptr) {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
            temp = temp->next;
        }
    }
}

int main() {
    Queue Q;
    createQueue(Q);

    // Contoh input dari user
    enqueue(Q, "Andi", 67890);
    enqueue(Q, "Budi", 12345);
    enqueue(Q, "Cici", 54321);

    viewQueue(Q);

    dequeue(Q);
    viewQueue(Q);

    return 0;
}
