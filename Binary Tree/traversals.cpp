#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        // by default, left and right children are NULL
        data = d;
        left = NULL;
        right = NULL;
    }
};

// tree will return address of root node
node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printInorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->left);
}

void printPreorder(node *root)

{
    if (root == NULL)
    {
        return;
    }

    // otherwise, print root first followed by subtrees(chilren)
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->left);
    cout << root->data << " ";
}

int main()
{
    node *root = buildTree();

    cout << "Preorder: ";
    printPreorder(root);

    cout << endl;

    cout << "Inorder: ";
    printInorder(root);

    cout << endl;

    cout << "Preorder: ";
    printPostorder(root);

    cout << endl;
}
