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
        Q.back->next = newNode;
        Q.back = newNode;
    }
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
        cout << "Data antrian mahasiswa:" << endl;
        while (temp != nullptr) {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
            temp = temp->next;
        }
    }
}

int main() {
    Queue Q;
    createQueue(Q);

    enqueue(Q, "Andi", 12345);
    enqueue(Q, "Budi", 67890);

    viewQueue(Q);

    dequeue(Q);
    viewQueue(Q);

    return 0;
}