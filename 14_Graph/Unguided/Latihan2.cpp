#include <iostream>
#include <vector>

using namespace std;

int main() {
    int jumlahSimpul, jumlahSisi;

    cout << "masukan jumlah simpul : ";
    cin >> jumlahSimpul;
    cout << "masukan jumlah sisi : ";
    cin >> jumlahSisi;

    vector<vector<int>> adjacencyMatrix(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    cout << "masukan pasangan simpul : " << endl;
    for (int i = 0; i < jumlahSisi; i++) {
        int simpul1, simpul2;
        cin >> simpul1 >> simpul2;
        adjacencyMatrix[simpul1 - 1][simpul2 - 1] = 1; 
        adjacencyMatrix[simpul2 - 1][simpul1 - 1] = 1;
    }
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}



