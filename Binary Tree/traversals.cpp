#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *insert(node *root, int x)
{
    if (root == NULL)
        return new node(x);

    else if (root->data < x)
        root->right = insert(root->right, x);

    else if (root->data >= x)
        root->left = insert(root->left, x);

    return root;
}

void prePrint(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    prePrint(root->left);
    prePrint(root->right);
}

void printRange(node *root, int k1, int k2)
{
    // if (root == NULL)
    //     return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *f = q.front();
        if (f->data >= k1 and f->data <= k2)
            cout << f->data << " ";

        q.pop();

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}


int main()
{

    node *root = insert(root, 20);
    root->left = insert(root->left, 8);
    root->right = insert(root->right, 22);
    // node *root = buildTree();

    node *newl = insert(root, 4);
    node *newr = insert(root, 12);

    prePrint(root);
    cout << endl;

    printRange(root, 10, 25);
}
