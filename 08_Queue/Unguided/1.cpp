#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* back;
};
void createQueue(Queue &Q) {
    Q.front = nullptr;
    Q.back = nullptr;
}
bool isEmptyQueue(Queue &Q) {
    return Q.front == nullptr;
}
void enqueue(Queue &Q, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if(isEmptyQueue(Q)) {
        Q.front = newNode;
        Q.back = newNode; 
    }else {
        Q.back->next = newNode;
        Q.back = newNode;
    }
}

void dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrian Kosong" << endl;
    } else {
        Node* temp = Q.front;
        Q.front = Q.front->next;
        delete temp;
        if(Q.front == nullptr) {
            Q.back = nullptr;
        }
    }
}

void viewQueue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrian kosong!" << endl;
    } else {
        Node* temp = Q.front;
        cout << "Data antrian: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    Queue Q;
    createQueue(Q);

    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);

    viewQueue(Q);

    dequeue(Q);
    viewQueue(Q);

    return 0;
}