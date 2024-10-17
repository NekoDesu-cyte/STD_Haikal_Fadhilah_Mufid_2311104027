#include <iostream>
#include "list.h"

using namespace std;

int main() {
    List L;
    createList(L);

    int input;
    std::cout << "Masukan angka: ";
    std::cin >> input;

    address P = allocate(input);

    insertFirst(L, P);

    printInfo(L);

    std::cout << "Masukan angka kedua: ";
    std::cin >> input;
    
    P = allocate(input);
    insertFirst(L, P);

    printInfo(L);

    std::cout << "Masukan angka ketiga: ";
    std::cin >> input;
    
    P = allocate(input);
    insertFirst(L, P);

    printInfo(L);

    return 0;

}