#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};

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

void rightView(node *root, int level, int &maxLevel)
{
    if (root == NULL)
    {
        return;
    }
    if (maxLevel < level)
    {
        //discovered a new level
        cout << root->data << " ";
        maxLevel = level;
    }

    rightView(root->right, level + 1, maxLevel);
    rightView(root->left, level + 1, maxLevel);
}

int main()
{

    node *root = buildTree();

    node*target = root->left->left;

    int maxLevel = -1;

    rightView(root, 0, maxLevel);
}
