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
    }Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

bool searchNode(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int countLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

int main() {
    Node* head = nullptr;

    insertFront(head, 10);
    insertBack(head, 20);
    insertFront(head, 5);

    cout << "isi linked list:";
    printList(head);

    int valueToSearch = 20;
    if (searchNode(head, valueToSearch)) {
        cout << "Node dengan nilai " << valueToSearch << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << valueToSearch << " tidak ditemukan." << endl;
    }
    int length = countLength(head);
    cout << "Panjang linked list " << length << endl;

    return 0;       
}