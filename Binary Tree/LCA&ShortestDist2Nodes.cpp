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
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *lca(node *root, int a, int b)
{
    if (root == NULL)
        return NULL;

    if (root->data == a or root->data == b)
        return root;

    node *leftans = lca(root->left, a, b);
    node *rightans = lca(root->right, a, b);

    if (leftans != NULL and rightans != NULL)
        return root;

    if (leftans != NULL)
        return leftans;

    return rightans;
}

// finds the level of a given node from root node or any given node
int search_shortestDistance(node *root, int key, int level)
{

    if (root == NULL)
        return -1;

    if (root->data == key)
    {
        return level;
    }

    int left = search_shortestDistance(root->left, key, level + 1);

    if (left != -1)
        return left;

    return search_shortestDistance(root->left, key, level + 1);
}

// finds shortest dist b/w 2
int shortestDistance(node *root, int a, int b)
{
    node *lca_node = lca(root, a, b);

    int level1 = search_shortestDistance(lca_node, a, 0);
    int level2 = search_shortestDistance(lca_node, b, 0);

    return level1 + level2;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);

    int a = 7, b = 9;

    cout << "LCA of 4 and 10: " << lca(root, 4, 10)->data << endl;
    // cout << "LCA of 6 and 9: " << lca(root, 6, 9)->data << endl;
    cout << "Shortest dist b/w 4 and 14: " << shortestDistance(root, 1, 2) << endl;
}
