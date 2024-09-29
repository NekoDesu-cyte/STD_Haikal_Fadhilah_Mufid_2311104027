#include <iostream>
#include <string>

using namespace std;

string angkakehuruf(int angka){
    if (angka < 0 || angka > 100) return "Angka Melebihi Kapasitas";

    string satuan[] = {"null", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh","sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapam belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if (angka == 100) return "seratus";
    if (angka < 10) return satuan[angka];
    if (angka < 20) return belasan[angka - 10];

    string result = puluhan[angka / 10];
    if (angka % 10!=0) {
        result += " " + satuan[angka % 10];

    }

    return result;
    
}

int main () {
    int angka;

    cout << "Masukin angkanya (jangan lebih dari 100) = ";
    cin >> angka;

    string result = angkakehuruf(angka);
    cout << "Angka dalam tulisan: " <<result << endl;

    return 0;

}