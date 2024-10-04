#include <iostream>
#include <vector>

using namespace std;
    
int main() {
    int number;
    vector<int> genap;
    vector<int> ganjil;

    cout << "Masukan Angka = ";
    
    while (cin >> number && number!=-1) {
        if (number %2 == 0) {
            genap.push_back(number);
        }
        else {
            ganjil.push_back(number);    
    }
}

cout << "Bilangan genap = ";
for (int i = 0; i < genap.size(); i++) {
    cout << genap[i];
    if (i < genap.size() - 1) {
        cout << ", ";
    }
}
cout << endl;

cout << "Bilangan ganjil = ";
for (int i = 0; i < ganjil.size(); i++) {
    cout << ganjil[i];
    if (i < ganjil.size() - 1) {
        cout << " ,";
    }
}
cout << endl;

return 0;
}