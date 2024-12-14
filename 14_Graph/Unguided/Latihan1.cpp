#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int jumlahSimpul;
    cout << "SIlahkan masukan jumlah Simpul";
    cin >> jumlahSimpul;

    vector<string> namaSimpul(jumlahSimpul);
    cout << "SIlahkan masukan nama Simpul " << endl;
    for (int i = 0; i< jumlahSimpul; i++) {
        cout << "simpul" << i + 1 << " : ";
        cin >> namaSimpul[i]; 
    }

    vector<vector<int>> bobot (jumlahSimpul, vector <int>(jumlahSimpul, 0));

    cout << "SIlahkan masukan bobot antar simpul " << endl;
    for (int i=0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << namaSimpul[i] << "-> " << namaSimpul[j] << " = ";
            cin >> bobot[i][j];
        }
    }

    cout << "\nAdjacency Matrix:" << endl;
    cout << "  ";
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << namaSimpul[i] << " ";
    }
    cout << endl;

    for (int i = 0; i< jumlahSimpul; i++) {
        cout << namaSimpul[i] << " ";
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << bobot[i][j] << " ";
        }     
        cout << endl;
    }

    return 0;
}
