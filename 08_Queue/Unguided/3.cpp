#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    Mahasiswa* next;
};

struct Queue {
    Mahasiswa* front;
    Mahasiswa* back;
};

void createQueue(Queue &Q) {
    Q.front = nullptr;
    Q.back = nullptr;
}

bool isEmptyQueue(Queue &Q) {
    return Q.front == nullptr;
}

void enqueue(Queue &Q, string nama, int nim) {
    Mahasiswa* newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmptyQueue(Q)) {
        Q.front = newNode;
        Q.back = newNode;
    } else {
        // Sisipkan berdasarkan prioritas NIM
        if (nim < Q.front->nim) {
            newNode->next = Q.front;
            Q.front = newNode;
        } else {
            Mahasiswa* temp = Q.front;
            while (temp->next != nullptr && temp->next->nim < nim) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            if (newNode->next == nullptr) {
                Q.back = newNode;
            }
        }
    }
    cout << "Mahasiswa " << nama << " dengan NIM " << nim << " ditambahkan ke antrian." << endl;
}

void dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrian kosong!" << endl;
    } else {
        Mahasiswa* temp = Q.front;
        cout << "Mahasiswa " << temp->nama << " dengan NIM " << temp->nim << " dikeluarkan dari antrian." << endl;
        Q.front = Q.front->next;
        delete temp;
        if (Q.front == nullptr) {
            Q.back = nullptr;
        }
    }
}

void viewQueue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrian kosong!" << endl;
    } else {
        Mahasiswa* temp = Q.front;
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
