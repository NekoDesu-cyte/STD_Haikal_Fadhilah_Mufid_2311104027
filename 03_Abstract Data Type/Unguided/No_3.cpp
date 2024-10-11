#include <iostream>

using namespace std;

void menampilkanArray2D(int array [3] [3]);
void menukarArray2D(int array [3] [3], int array2 [3] [3], int baris, int kolom);
void menukarPointer(int * prt1, int *ptr2);

int main() {
    int array1 [3] [3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int array2 [3] [3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    cout << "Array 1 = " <<endl;
    menampilkanArray2D(array1);
    cout << "Array 2 = " <<endl;
    menampilkanArray2D(array2);

    menukarArray2D(array1, array2, 1, 1);
    cout << "\nSetelah menukar elemen pada posisi (1,1) = "<<endl;
    cout << "Array 1 = " <<endl;
    menampilkanArray2D(array1);
    cout << "Array 2 = " <<endl;
    menampilkanArray2D(array2);
    
    int a = 5, b = 10;
    int* ptr1 = &a;
    int* ptr2 = &b;

    cout << "\nNilai sebelum ditukar = " << *ptr1 << ", " << *ptr2 << endl;

    menukarPointer(ptr1, ptr2);
    cout << "Nilai setelah ditukar = " << *ptr1 << ", " << *ptr2 << endl;

    return 0;
}

    void menampilkanArray2D(int array[3][3]) {
           for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << array[i] [j] << " " ;
            }
            cout << endl;
    }
}
     
    void menukarArray2D(int array1[3][3], int array2 [3][3], int baris, int kolom) {
        int temp = array1[baris][kolom];
        array1[baris][kolom] = array2[baris][kolom];
        array2[baris][kolom] = temp;
}

    void menukarPointer(int* ptr1, int* ptr2){
        int temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
}


