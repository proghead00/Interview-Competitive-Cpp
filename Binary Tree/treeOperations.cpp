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

int count(node *root)
{
    if (root == NULL)
        return 0;

    return 1 + count(root->left) + count(root->right);
}

class Pair
{
public:
    int height;
    int diameter;
};

Pair diameter(node *root)

{
    Pair p;
    if (root == NULL)
    {
        p.height = 0;
        p.diameter = 0;
        return p;
    }

    // otherwise
    Pair left = diameter(root->left);
    Pair right = diameter(root->right);

    p.height = max(left.height, right.height) + 1;

    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));

    return p;
}

int optimizedHeight(node *root)
{
    int res = 0;
    if (root == NULL)
    {
        return 0;
    }
    int lh = optimizedHeight(root->left);
    int rh = optimizedHeight(root->right);

    res = max(res, lh + rh + 1);

    return 1 + max(lh, rh);
}

class HeightBalancedPair
{
public:
    int height;
    bool balance;
};

HeightBalancedPair isHeightBalanced(node *root)
{
    HeightBalancedPair p;
    if (root == NULL)
    {
        p.height = 0;
        p.balance = true;
        return p;
    }

    // postorder
    HeightBalancedPair left = isHeightBalanced(root->left); //
    HeightBalancedPair right = isHeightBalanced(root->right);

    p.height = max(left.height, right.height) + 1;

    if (abs(left.height - right.height) <= 1 and left.balance and right.balance)
        p.balance = true;

    else
        p.balance = false;

    return p;
}

node *buildTreeFromArray(int *a, int s, int e)
{
    // base case
    if (s > e)
        return NULL;

    // rec case
    int mid = (s + e) / 2;
    node *root = new node(a[mid]);
    root->left = buildTreeFromArray(a, s, mid - 1);
    root->right = buildTreeFromArray(a, mid + 1, e);
    return root;
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

int main()
{
    // node *root = buildTree();
    // cout << "No. of nodes: " << count(root) << endl;

    // Pair p = diameter(root);

    // cout << "Diameter: " << p.diameter << endl;
    // // cout << "Diameter: " << optimizedHeight(root) << endl;

    // if (isHeightBalanced(root).balance) cout << "Balanced"; else cout << "Not balanced";

    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;

    node *root = buildTreeFromArray(a, 0, n - 1);
    bfs(root);
}
