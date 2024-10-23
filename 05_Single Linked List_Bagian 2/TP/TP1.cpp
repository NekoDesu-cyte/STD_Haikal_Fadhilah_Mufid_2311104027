#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert_2311104027(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if(head == nullptr) {
        head = newNode;
    } else 
    {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void searchElement(Node* head, int value) {
    Node* current = head;
    int position = 1;

    while (current != nullptr) {
        if (current->data == value) {
            cout << "Element " << value <<" found at address" << current << " and position " << position << endl;
            return;
        }
        current = current-> next;
        position++;
    }
    cout << "Element " << value << " not found in the list." << endl;
}

int main () {
    Node* head = nullptr;
    int value;

    cout << "Enter 6 integer values for the list : " << endl;
    for (int i = 0; i < 6; i++) {
        cin >> value;
        insert_2311104027(head, value);
    }
    cout << "enter the element to search : ";
    cin >> value;

    searchElement(head, value);

    return 0;
}