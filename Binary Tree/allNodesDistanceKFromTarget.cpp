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
    {
        return NULL;
    }

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// prints all nodes which are k-level below the target node
void printSubtreeNodes(node *root, int k)
{
    if (root == NULL || k < 0)
        return;

    if (k = 0)
    {
        cout << root->data << " ";
        return;
    }

    printSubtreeNodes(root->left, k - 1);
    printSubtreeNodes(root->right, k - 1);

    return;
}

// from every node, return the distance of the target node from that particular node
int printNodesAtK(node *root, node *target, int k)
{

    // base
    if (root == NULL)
        return -1;

    // reaches target node
    if (root == target)
    {
        printSubtreeNodes(target, k);
        return 0;
    }

    // ancestor -> find target node in left and right subtree

    int DL = printNodesAtK(root->left, target, k);

    if (DL != -1)
    {
        // ancestor(root node) itself or go to right of ancestor
        if (DL + 1 == k)

            cout << root->data << " ";

        else

            printSubtreeNodes(root->right, k - 2 - DL);

        return 1 + DL;
    }

    int DR = printNodesAtK(root->right, target, k);

    if (DR != -1)
    {
        if (DR + 1 == k)
            cout << root->data << " ";

        else
            printSubtreeNodes(root->left, k - 2 - DR);

        return 1 + DR;
    }

    // node's not present in either left or right
    return -1;
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

    // node *root = buildTree();

    // node *target = root->left;

    // int k;
    // cin >> k;
    // bfs_lineByLine(root);

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    bfs_lineByLine(root);
    cout<< "Nodes in neighbour: ";
    printNodesAtK(root, root->left, 1);
}
