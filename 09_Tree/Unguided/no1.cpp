#include <iostream>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root;

void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

void buatNode(char data) {
    if(isEmpty()) {
        root = new Pohon{data, NULL, NULL, NULL};
    } else {
        cout << "Pohon sudah dibuat" << endl;
    }
}

Pohon* insertLeft(char data, Pohon *node) {
    if(isEmpty()) {
        cout << "Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->left != NULL) {
        cout << "Node " << node->data << " sudah ada child kiri!" << endl;
        return NULL;
    }

    Pohon *baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "Node " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

Pohon* insertRight(char data, Pohon *node) {
    if(isEmpty()) {
        cout << "Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->right != NULL) {
        cout << "Node " << node->data << " sudah ada child kanan!" << endl;
        return NULL;
    }

    Pohon *baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "Node " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

void update(char data, Pohon *node) {
    if(isEmpty()) {
        cout << "Buat tree terlebih dahulu!" << endl;
        return;
    }
    if(!node) {
        cout << "Node yang ingin diganti tidak ada!" << endl;
        return;
    }
    char temp = node->data;
    node->data = data;
    cout << "Node " << temp << " berhasil diubah menjadi " << data << endl;
}

void retrieve(Pohon *node) {
    if(isEmpty()) {
        cout << "Buat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node) {
        cout << "Node yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "Data node: " << node->data << endl;
}

void find(Pohon *node) {
    if(isEmpty()) {
        cout << "Buat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node) {
        cout << "Node yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "Data node: " << node->data << endl;
    cout << "Root: " << root->data << endl;
    cout << "Parent: " << (node->parent ? node->parent->data : '-') << endl;
    if (node->parent) {
        if (node->parent->left == node && node->parent->right)
            cout << "Sibling: " << node->parent->right->data << endl;
        else if (node->parent->right == node && node->parent->left)
            cout << "Sibling: " << node->parent->left->data << endl;
        else
            cout << "Sibling: Tidak ada sibling" << endl;
    }
}

void displayChild(Pohon *node) {
    if (!node) {
        cout << "Node yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "Node " << node->data << " memiliki:" << endl;
    cout << " - Child kiri: " << (node->left ? node->left->data : '-') << endl;
    cout << " - Child kanan: " << (node->right ? node->right->data : '-') << endl;
}

void displayDescendants(Pohon *node) {
    if (!node) {
        cout << "Node yang ditunjuk tidak ada!" << endl;
        return;
    }
    if (node->left) {
        cout << node->left->data << " ";
        displayDescendants(node->left);
    }
    if (node->right) {
        cout << node->right->data << " ";
        displayDescendants(node->right);
    }
}

void menu() {
    int pilihan;
    char data;
    Pohon *node;
    
    do {
        cout << "\nMenu Operasi Tree:" << endl;
        cout << "1. Buat Root Node" << endl;
        cout << "2. Tambah Node Kiri" << endl;
        cout << "3. Tambah Node Kanan" << endl;
        cout << "4. Retrieve Node" << endl;
        cout << "5. Find Node" << endl;
        cout << "6. Update Node" << endl;
        cout << "7. Tampilkan Child dari Node" << endl;
        cout << "8. Tampilkan Descendant dari Node" << endl;
        cout << "9. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                cout << "Masukkan data node kiri: ";
                cin >> data;
                node = root; // Sesuaikan dengan node yang diinginkan
                insertLeft(data, node);
                break;
            case 3:
                cout << "Masukkan data node kanan: ";
                cin >> data;
                node = root; // Sesuaikan dengan node yang diinginkan
                insertRight(data, node);
                break;
            case 4:
                retrieve(root); // Sesuaikan dengan node yang diinginkan
                break;
            case 5:
                find(root); // Sesuaikan dengan node yang diinginkan
                break;
            case 6:
                cout << "Masukkan data baru untuk update: ";
                cin >> data;
                update(data, root); // Sesuaikan dengan node yang diinginkan
                break;
            case 7:
                displayChild(root); // Sesuaikan dengan node yang diinginkan
                break;
            case 8:
                cout << "Descendants dari Node: ";
                displayDescendants(root); // Sesuaikan dengan node yang diinginkan
                cout << endl;
                break;
            case 9:
                cout << "Keluar" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 9);
}

int main() {
    init();
    menu();
    return 0;
}
