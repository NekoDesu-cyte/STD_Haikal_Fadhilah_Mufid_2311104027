#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string namaMahasiswa;
    int nimMahasiswa;
    Mahasiswa* next;
};

struct Queue {
    Mahasiswa* front;
    Mahasiswa* rear;
};

void initializeQueue(Queue &queue) {
    queue.front = nullptr;
    queue.rear = nullptr;
}

bool isQueueEmpty(Queue &queue) {
    return queue.front == nullptr;
}

void addStudent(Queue &queue, string nama, int nim) {
    Mahasiswa* newStudent = new Mahasiswa;
    newStudent->namaMahasiswa = nama;
    newStudent->nimMahasiswa = nim;
    newStudent->next = nullptr;

    if (isQueueEmpty(queue)) {
        queue.front = newStudent;
        queue.rear = newStudent;
    } else {
        queue.rear->next = newStudent;
        queue.rear = newStudent;
    }
}

void removeStudent(Queue &queue) {
    if (isQueueEmpty(queue)) {
        cout << "Queue is empty!" << endl;
    } else {
        Mahasiswa* temp = queue.front;
        cout << "Mahasiswa " << temp->namaMahasiswa << " dengan NIM " << temp->nimMahasiswa << " dikeluarkan dari antrian." << endl;
        queue.front = queue.front->next;
        delete temp;
        if (queue.front == nullptr) {
            queue.rear = nullptr;
        }
    }
}

void displayQueue(Queue &queue) {
    if (isQueueEmpty(queue)) {
        cout << "Queue is empty!" << endl;
    } else {
        Mahasiswa* temp = queue.front;
        cout << "Data antrian mahasiswa:" << endl;
        while (temp != nullptr) {
            cout << "Nama: " << temp->namaMahasiswa << ", NIM: " << temp->nimMahasiswa << endl;
            temp = temp->next;
        }
    }
}

int main() {
    Queue queue;
    initializeQueue(queue);

    addStudent(queue, "Andi", 12345);
    addStudent(queue, "Budi", 67890);

    displayQueue(queue);

    removeStudent(queue);
    displayQueue(queue);

    return 0;
}
