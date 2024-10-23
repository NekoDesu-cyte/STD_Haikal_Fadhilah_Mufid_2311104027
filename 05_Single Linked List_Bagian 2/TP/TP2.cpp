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
    }else
    {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void bubbleSortList(Node* head) {
    if(head == nullptr) return;

    bool swapped;
    Node* current;
    Node* lastSorted = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != lastSorted) {
            if(current->data > current->next->data) {

                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        lastSorted = current;
    } while (swapped);
}

int main () {
    Node* head = nullptr;
    int value;

    cout << "enter 5 integer values for the list : " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> value;
        insert_2311104027 (head, value);
    }

    cout << "Unsorted List : ";
    displayList(head);

    bubbleSortList(head);

    cout << "Sorted List : ";
    displayList(head);

    return 0;
}
