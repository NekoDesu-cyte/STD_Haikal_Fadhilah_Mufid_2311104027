#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

void insertLast_2311104027 (int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteFirst() {
    if (head == nullptr) {
        cout << "List kosong, tidak ada yang dihapus." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
}

void deleteLast() {
    if (head == nullptr) {
        cout << "List kosong, tidak ada yang dihapus" << endl;
        return;
    }

    Node* temp = head;

    if (temp->next == nullptr) {
        head = nullptr;
        delete temp;
        return;
    }
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
}

void displayList() {
    Node* temp = head;
    cout << "Daftar Anggota List : ";
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int data;

    cout << "Masukan Elemen Pertama : ";
    cin >> data;
    insertLast_2311104027(data);

    cout << "Masukan Elemen Kedua di akhir : ";
    cin >> data;
    insertLast_2311104027(data);

    cout << "Masukan Elemen Ketiga di akhir : ";
    cin >> data;
    insertLast_2311104027(data);

    deleteFirst();

    deleteLast();

    displayList();

    return 0;
}