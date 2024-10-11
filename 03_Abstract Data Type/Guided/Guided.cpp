#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct mahasiswa
{
 char nim[10];
 int nilai1,nilai2;
};
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

int main()
{
 mahasiswa mhs;
 inputMhs(mhs);
 cout << "rata-rata: " << rata2(mhs) << endl;
 return 0;
}
void inputMhs(mahasiswa &m)
{
 cout << "input nama = ";
 cin >> (m).nim;
 cout << "input nilai pertama= ";
 cin >> (m).nilai1;
 cout << "input nilai kedua = ";
 cin >> (m).nilai2;
}
float rata2(mahasiswa m){
 return (m.nilai1+m.nilai2)/2;
}