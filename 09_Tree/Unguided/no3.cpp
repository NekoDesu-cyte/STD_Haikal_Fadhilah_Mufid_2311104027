#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int cari_simpul_daun(Node* node) {
    if (node == NULL)
        return 0;

    if (node == NULL)
        return 0;

    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

int main() {
  
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);
    
    cout << "Jumlah simpul daun: " << cari_simpul_daun(root) << endl;

    return 0;
}