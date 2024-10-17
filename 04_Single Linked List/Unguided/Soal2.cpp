#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout <<temp->data;
        if (temp->next != nullptr) {
            cout <<"->";
        }
        temp = temp->next;
    }
    cout << endl;
}

void insertFront(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value; 
    newNode->next = head;
    head = newNode;
}

void insertBack(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "Linked list kosong, tidak ada node yang dibusek" << endl;
        return;
    }
    if(head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node dengan nilai" << value <<" telah dihapus. " << endl;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }
    if(temp->next !=nullptr) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Node Dengan Nilai " << value << " telah dihapus." << endl
    } else {
        cout << "Node dengan nilai " << value << " tidak ditemukan. " << endl;
    }
}

int main() {
    Node* head = nullptr;

    insertFront(head, 10);

    insertBack(head, 20);

    insertFront(head, 5);

    cout <<"isi linked list sebelum penghapusan : ";
    printList(head);

    deleteNode(head, 10);

    cout << "isi linked list setelah penghapusan :";
    printList(head);

    return 0;
}