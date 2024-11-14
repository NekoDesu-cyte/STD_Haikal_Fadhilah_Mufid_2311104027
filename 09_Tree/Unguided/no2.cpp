#include <iostream>
#include <limits.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
     Node(int val) : data(val), left(NULL), right(NULL) {}
};

bool is_valid_bst(Node* node, int min_val, int max_val) {
    if (node == NULL)
        return true;

        if (node->data <= min_val || node->data >= max_val)
        return false;

       return is_valid_bst(node->left, min_val, node->data) &&
              is_valid_bst(node->right, node->data, max_val);
}

bool is_valid_bst(Node* root) {
    return is_valid_bst(root, INT_MIN, INT_MAX);
}

int main() {
    Node*  root1 = new Node(10);
    root1->left = new Node(5);
    root1->right = new Node(15);
    root1->left->left = new Node(2);
    root1->left->right = new Node(7);
    root1->right->right = new Node(20);

    cout << "Pohon pertama (valid BST) : " << (is_valid_bst(root1) ? "Valid" : "Tidak Valid") << endl;

    Node*  root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(15);
    root2->left->left = new Node(2);
    root2->left->right = new Node(12); 

    cout << "Pohon kedua (invalid BST) : " << (is_valid_bst(root2) ? "Valid" : "Tidak Valid") << endl;

    return 0;
}