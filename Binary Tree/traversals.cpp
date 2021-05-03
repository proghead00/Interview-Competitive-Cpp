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

int height(node *root)
{
    if (root == NULL)
        return 0;

    int leftSubtree = height(root->left);
    int rightSubtree = height(root->right);

    return max(leftSubtree, rightSubtree) + 1;
}

void kthLevel(node *root, int k)
{
    if (root == NULL)
        return;

    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }

    kthLevel(root->left, k - 1);
    kthLevel(root->right, k - 1);

    return;
}

// o(n*n)
void allLevels(node *root)
{
    int h = height(root);

    for (size_t i = 0; i <= h; i++)
    {
        kthLevel(root, i);
        cout << endl;
    }
    return;
}

void bfs(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {

        node *f = q.front();
        cout << f->data << " ";

        q.pop();

        if (f->left) // if left child isn't NULL
            q.push(f->left);

        if (f->right) // if right child isn't NULL
            q.push(f->right);
    }
    return;
}

void bfs_lineByLine(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        node *f = q.front();
        if (f == NULL)
        {
            cout << endl;
            q.pop();

            if (!q.empty())
                q.push(NULL);
        }

        else // else print data as usual
        {
            cout << f->data << " ";

            q.pop();

            if (f->left) // if left child isn't NULL
                q.push(f->left);

            if (f->right) // if right child isn't NULL
                q.push(f->right);
        }
    }
    return;
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

    cout << "BFS: ";
    bfs(root);

    cout << endl;

    cout << "BFS line by line: \n ";
    bfs_lineByLine(root);

    cout << endl;
}
