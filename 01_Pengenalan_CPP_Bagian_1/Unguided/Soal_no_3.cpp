#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    for (int i = n; i > 0; i--) {
        for (int k = n - i; k > 0; k--) {
            cout << "  ";  
        }
        for (int j = i; j > 0; j--) {
            cout << j << " ";
        }

        cout << "* ";
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl; 
    }

    
    for (int k = 0; k < n; k++) {
        cout << "  "; 
    }
    cout << "* " << endl;

    return 0;
}