#include <iostream>
#include <queue>
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

node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}
// O(h): time and space
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

bool search(node *root, int x)
{
    // base
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    else if (root->data < x)
        return search(root->right, x); // return what right subtree returns

    else if (root->data >= x)
        return search(root->left, x);
}

node *getSuccessorRChildEmpty(node *curr)
{
    curr = curr->right;

    while (curr != NULL and curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

node *deleteBST2(node *root, int x)
{
    if (root = NULL)
        return root;

    if (root->data > x)
        root->left = deleteBST2(root->left, x);

    else if (root->data < x)
        root->right = deleteBST2(root->right, x);

    else
    { // when root->data == x
        if (root->left == NULL)
        {

            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {

            node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            node *succ = getSuccessorRChildEmpty(root);
            root->data = succ->data;
            root->right = deleteBST2(root->right, succ->data);
        }
        return root;
    }
}
// node *deleteBST(node *root, int key)
// {
//     if (root == NULL)
//         return NULL;

//     else if (key < root->data)
//     {
//         root->left = deleteBST(root->left, key);
//         return root;
//     }

//     else if (key == root->data)
//     {
//         // case 1: node w/ 0 children
//         if (root->left == NULL and root->right == NULL)
//         {
//             delete root;
//             return NULL; // return NULL to the parent
//         }

//         // case 2: only 1 child
//         if (root->left != NULL and root->right == NULL)
//         {
//             node *temp = root->left;
//             delete root;
//             return temp;
//         }
//         if (root->right != NULL and root->left == NULL)
//         {
//             node *temp = root->right;
//             delete root;
//             return temp;
//         }

//         // case 3: 2 children -> replace w/ inorder successor
//         node *replace = root->right;
//         // finds the inorder successor from right subtree
//         while (replace->left != NULL)
//         {
//             replace = replace->left;
//         }
//         root->data = replace->data;
//         root->right = deleteBST(root->right, replace->data);
//     }

//     else
//     {
//         root->right = deleteBST(root->right, key);
//         return root;
//     }
// }

void bfs_lineByline(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            cout << "\n";
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << f->data << " ";
            q.pop();

            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }
    }
    return;
}

int main()
{
    node *root = insert(root, 5);
    root->left = insert(root->left, 3);
    root->right = insert(root->right, 6);
    // node *root = buildTree();

    node *root = new node(5);
    root->left = new node(3);
    root->right = new node(6);

    node *newl = insert(root, 4);
    node *newr = insert(root, 7);
    bfs_lineByline(root);

    root = deleteBST2(root, 3);
    bfs_lineByline(root);

    // bool found = search(root, 7);
    // (found == true) ? cout << "Found" : cout << "Not found";
}
