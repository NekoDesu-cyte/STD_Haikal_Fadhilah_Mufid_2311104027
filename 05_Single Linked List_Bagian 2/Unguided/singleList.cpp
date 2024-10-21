#include "singleList.h"

void createList(List& L) {
    L.First = nullptr;
}

address alokasi(infotype X) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = X;
        P->next = nullptr;
    }
    return P;
}
//Menanmbahkan jawaban untuk menjawab soal no 3
address findElm(List L, infotype X) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
//Batas menambahkan untuk soal no 3

void dealokasi(address& P) {
    delete P;
    P = nullptr;
}

void printInfo(const List& L) {
    address P = L.First;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List& L, address P) {
    if (P != nullptr) {
        P->next = L.First;
        L.First = P;
    }
}

//Penambahan jawaban no 4
int sumElement(List L) {
    int sum = 0;
    address P = L.First;
    while (P != nullptr) {
        sum += P->info;
        P = P->next;
    }
    return sum;
}