#include <iostream>

using namespace std;

int nyariMaksimum(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

int nyariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

double nyariRataRata(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return (double)total / n;
}

int main() {
    int n;

    cout << "Masukkan jumlah elemen array =  ";
    cin >> n;

    int arr[n];
    cout << "Masukkan elemen array =\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    // Langsung menampilkan hasil
    cout << "Nilai minimum = " << nyariMinimum(arr, n) << endl;
    cout << "Nilai maksimum = " << nyariMaksimum(arr, n) << endl;
    cout << "Nilai rata-rata = " << nyariRataRata(arr, n) << endl;

    return 0;
}
