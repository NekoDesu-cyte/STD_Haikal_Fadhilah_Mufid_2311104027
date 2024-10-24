#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

void insertSorted_231114027(int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if (head == nullptr) {
        newNode->prev = nullptr;
        newNode->next = nullptr;
        head = newNode;
        return;
    }

    if (data <= head->data) {
        newNode->next = head;
        newNode->prev = nullptr;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data < data) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
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

    cout << "Masukan Elemen pertama : ";
    cin >> data;
    insertSorted_231114027(data);

    cout << "Masukan Elemen kedua di awal  : ";
    cin >> data;
    insertSorted_231114027(data);

    cout << "Masukan Elemen ketiga di akhir : ";
    cin >> data;
    insertSorted_231114027(data);
    
    

    displayList();

    return 0;

}