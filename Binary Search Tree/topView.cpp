#include <bits/stdc++.h>
#include <map>
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

// queue -> for level order
// map -> <hd,  node's data> if hd's not already taken
void topView(node *root)
{
    map<int, vector<int>> mp;
    queue<pair<node *, int>> q;

    q.push({root, 0});

    // level order
    while (!q.empty())
    {
        auto f = q.front();

        node *curr = f.first;
        int hd = f.second;

        if (!mp.count(hd))
            mp[hd].push_back(curr->data);

        q.pop();

        // enq the children
        if (curr->left)
            q.push({curr->left, hd - 1});
        if (curr->right)
            q.push({curr->right, hd + 1});
    }

    for (auto p : mp)
    {
        vector<int> v = p.second;

        for (auto x : v)
            cout << x << " ";

        cout << endl;
    }
}

void inorder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
    return;
}

int main()
{

    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(50);
    root->right->left = new node(60);
    root->left->right = new node(40);
    root->left->left = new node(30);
    cout << "Inorder:";
    inorder(root);
    cout << endl;
    topView(root);
}
