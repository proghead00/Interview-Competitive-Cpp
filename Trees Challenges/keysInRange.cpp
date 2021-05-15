
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void Print(node *root, int k1, int k2)
{

    if (root == NULL)
        return;

    if (k1 < root->data)
        Print(root->left, k1, k2);

    if (k1 <= root->data && k2 >= root->data)
        cout << root->data << " ";

    if (k2 > root->data)
        Print(root->right, k1, k2);
}



int main()
{

    int k1 = 10, k2 = 25;

    node *root = new node(20);
    root->left = new node(8);
    root->right = new node(22);
    root->left->left = new node(4);
    root->left->right = new node(12);

    Print(root, k1, k2);
    return 0;
}
