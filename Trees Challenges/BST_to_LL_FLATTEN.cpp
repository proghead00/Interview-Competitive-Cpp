#include <iostream>
#include <climits>
using namespace std;

int minv = INT_MIN;
int maxv = INT_MAX;

class node
{
public:
    int data;
    node *left;
    node *right;
};

class linkedlist
{
public:
    node *head;
    node *tail;
};

node *insertbst(node *root, int d)
{
    if (root == NULL)
    {
        root = new node();
        root->data = d;

        return root;
    }
    else if (root->data >= d)
    {
        root->left = insertbst(root->left, d);
    }
    else if (root->data < d)
    {
        root->right = insertbst(root->right, d);
    }
    return root;
}

node *build()
{

    int d;
    cin >> d;
    node *root = NULL;
    while (d != -1)
    {
        root = insertbst(root, d);
        cin >> d;
    }
    return root;
}

linkedlist flatten(node *root)
{
    linkedlist l;
    if (root == NULL)
    {
        l.head = l.tail = NULL;
        //missing:
        return l;
    }

    // leaf node
    if (root->left == NULL && root->right == NULL)
    {
        l.head = l.tail = root;
        return l;
    }

    if (root->left != NULL && root->right == NULL)
    {
        linkedlist ls = flatten(root->left);
        l.head = ls.head;

        //Missing:
        ls.tail->right = root;

        l.tail = root;
        return l;
    }
    if (root->left == NULL && root->right != NULL)
    {
        linkedlist rs = flatten(root->right);
        l.head = root;

        //Missing:
        root->right = rs.head;

        l.tail = rs.tail;
        return l;
    }

    linkedlist lst = flatten(root->left);
    linkedlist rst = flatten(root->right);
    lst.tail->right = root;
    root->right = rst.head;
    l.head = lst.head;
    l.tail = rst.tail;
    return l;
}

void print(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

int main()
{
    node *root = build();
    print(root);
    cout << endl;

    linkedlist l = flatten(root);
    node *temp = l.head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
}
