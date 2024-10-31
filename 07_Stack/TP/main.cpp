#include <iostream>
#include "Stack.h"

void testStack(const char* elements) {
    stack S;
    createStack(S);

    for (int i = 0; elements[i] != '\0'; i++) {
        push(S, elements[i]);
    }
    std::cout << "Isi stack awal: ";
    printInfo(S);

    std::cout << "Isi stack setelah pop: ";
    for (int i = 0; i < 4; i++) {
        pop(S);
    }
    printInfo(S);
}

int main() {
    int nimLastDigit = 0;
    switch (nimLastDigit) {
        case 0: testStack("IFLABJAYA"); break;
        case 1: testStack("HALOBANDUNG"); break;
        case 2: testStack("PERCAYADIRI"); break;
        case 3: testStack("STRUKTURDATA"); break;
    }
    return 0;
}
