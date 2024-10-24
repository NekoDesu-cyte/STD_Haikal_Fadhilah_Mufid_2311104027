#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void insertLast_2311104027(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void displayFromFront() {
    Node* temp = head;
    cout << "Daftar Elemen dari depan ke belakang : ";
    while (temp != nullptr) {
        cout << temp-> data;
        if (temp->next != nullptr) {
            cout << " <--> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void displayFromBack () {
    Node* temp = tail;
    cout << "Daftar Elemen dari belakang ke depan: ";
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->prev != nullptr) {
            cout << " <-> ";
        }
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    int data;

    for (int i = 1; i <= 4; i++) {
        cout << "Masukkan elemen ke-" << i << ": ";
        cin >> data;
        insertLast_2311104027(data);
    }


    displayFromFront();

    displayFromBack();

    return 0;
} 