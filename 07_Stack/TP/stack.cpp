#include <iostream>
#include "stack.h"

void createStack(stack &S) {
    S.Top = 0;
}
bool isEmpty(stack S) {
    return S.Top == 0;
}
bool isFull(stack S) {
    return S.Top == 15;
}
void push(stack &S, infotype x) {
    if (!isFull(S)) {
        S.Top += 1;
        S.info[S.Top -1] = x;
    } else {
        std::cout << "Stack penuh, tidak bisa menambah elemen" << std::endl;
    }
}

infotype pop(stack &S) {
    if(!isEmpty(S))  {
        infotype cc = S.info[S.Top - 1];
        S.Top -= 1;
        return cc;
    } else{
        std::cout << "Stack kosong, tidak ada elemen yang di pop" << std::endl;
        return '\0';
    }
}

void printInfo(stack S) {
    if(!isEmpty(S)) {
        for (int i = S.Top - 1; i >= 0; i--) {
            std::cout << S.info[i] << " ";
        }
        std::cout <<std::endl;
    }else {
        std::cout << "Stack kosong" << std::endl;
    }
}

