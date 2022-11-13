#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node *buildTree() {
    int d;
    cin >> d;

    if (d == -1)
        return NULL;

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void print(node* root) {
    if (!root) return;

    cout << root->data << endl;

    print(root->left);

    print(root->right);
}

int main() {
    node* root = buildTree();
    print(root);
}
