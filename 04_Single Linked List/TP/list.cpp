#include <iostream>
#include "list.h"
using namespace std;

void createList(List &L) {
    first(L) = NULL;
}

address allocate(infotype x){
    address p = new elmlist;
    info(p) = x;
    next(p) = NULL;

    return p;
}
void insertFirst(List &L, address P){
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        address last = first (L);
        while (next(last) != NULL) {
            last = next(last);
        }
        next(last) = P;
    }
}

void insertAfter(List &L, address P, address Prec) {
    if (Prec != NULL) {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteFirst(List &L) {
    if (first(L) != NULL) {
        address P = first(L);
        first(L) = next(P);
        delete P;
    }
}

void deleteLast(List &L) {
    if (first(L) != NULL) {
        address P = first(L);
        if(next(P) == NULL) {
            first(L) = NULL;
        } else {
            address q;
            while (next(P) != NULL) {
                q = P;
                P = next(P);
            }
            next(q) = NULL;
        }
        delete P;
    }
}

void deleteAfter(List &L, address Prec) {
    if (Prec != NULL && next(Prec) != NULL) {
        address p = next(Prec);
        next(Prec) = next(p);
        delete p;
    }
}

address searchInfo(List L, infotype x) {
    address p = first(L);
    while (p != NULL) {
        if (info(p) == x) {
            return p;
        }
        p = next(p);
    }
    return NULL;
}

void printInfo(List L){

    address p = first(L);
    while (p != NULL) {
        cout << info(p) << ", ";
        p = next(p);
    }
    cout << endl;
}