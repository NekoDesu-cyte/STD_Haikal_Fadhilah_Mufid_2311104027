#include "doubleList.h"

void createList (List& L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi (infotype X) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = X;
        P->next = nullptr;
        P->prev = nullptr;

    }
    return P;
}

void dealokasi (address& P){
    delete P;
    P = nullptr;
}

void printInfo (const List& L) {
    address P = L.First;
    while (P != nullptr) {
        cout << "No Polisi : " << P->info.nopol << endl;
        cout << "Warna     : " << P->info.warna << endl;
        cout << "Tahun     : " << P->info.thnBuat << endl;
        P = P->next;
        cout << endl;
    }
}

void insertLast(List& L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    }else 
    {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}
