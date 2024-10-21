#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>

using namespace std;

typedef int infotype;

struct ElmList{
    infotype info;
    ElmList* next;
    
};

typedef ElmList* address;

struct List {
    address First;    
};

void createList(List& L);
address alokasi(infotype X);
void dealokasi(address& P);
void printInfo(const List& L);
void insertFirst(List& L, address P);
//Menambahkan jawaban untuk soal no 3
address findElm (List L, infotype X);
//Batas penambahan untuk menjawab soal no 3

//Jawban soal no 4
int sumElement(List L);
//batas ---||-----
#endif