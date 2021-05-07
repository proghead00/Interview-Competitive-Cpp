#include <iostream>
using namespace std;

// A binary Tree node
class node
{
public:
    int data;
    node *left, *right;

    node(int d)
    {
        left = NULL;
        right = NULL;
        data = d;
    }
};

void printNodeSubtree(node *root, int k)
{
    // Base
    if (root == NULL || k < 0)
        return;

    // If we reach a k distant node, print it
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }

    // Recur for left and right subtrees
    printNodeSubtree(root->left, k - 1);
    printNodeSubtree(root->right, k - 1);
}

int printNodeAtK(node *root, node *target, int k)
{
    // Base
    if (root == NULL)
        return -1;

    if (root == target)
    {
        printNodeSubtree(root, k);
        return 0;
    }

    int dl = printNodeAtK(root->left, target, k); //   dl is distance of root's left child from target

    // Check if target node was found in left subtree
    if (dl != -1)
    {
        // If root is at distance k from target, print root

        if (dl + 1 == k)
            cout << root->data << endl;

        // else go to right subtree and print all k-dl-2 distant nodes
        else
            printNodeSubtree(root->right, k - dl - 2); //  the right child is 2 edges away from left child

        // Add 1 to the distance and return value for parent calls
        return 1 + dl;
    }

    //  it reaches here only when node was not found in left subtree
    int dr = printNodeAtK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
            cout << root->data << endl;
        else
            printNodeSubtree(root->left, k - dr - 2);
        return 1 + dr;
    }

    return -1;
}

int main()
{

    node *root = new node(20);
    root->left = new node(8);
    root->right = new node(22);
    root->left->left = new node(4);
    root->left->right = new node(12);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);
    node *target = root->left->right;
    printNodeAtK(root, target, 2);
    return 0;
}
