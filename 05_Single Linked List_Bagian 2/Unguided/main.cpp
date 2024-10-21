#include "singleList.h"

int main() {
    List L;
    address P1,P2,P3,P4,P5 = nullptr;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L,P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

//menambahkan untuk soal no 3
    address result = findElm(L, 0);
    if(result != nullptr) {
        cout  << "8 Ditemukan dalam list " << endl;
    } else 
    {
        cout << "404 not found" << endl;
    }
//batas kode yang ditambahkan untuk no 3

    int totalSum = sumElement(L);
    cout << "Total info dari kelima elemen adalah : " << totalSum << endl;

    return 0;
}