#include <bits/stdc++.h>
#include <map>
using namespace std;

class node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void vertTrav(node *root)
{
    map<int, vector<int>> mp;
    queue<pair<node *, int>> q;

    q.push({root, 0});

    // level order
    while (!q.empty())
    {
        auto p = q.front();
        node *curr = p.first;
        int hd = p.second;

        mp[hd].push_back(curr->data);

        q.pop();

        // enqueue the children
        if (curr->left != NULL)
            q.push({curr->left, hd - 1});

        if (curr->right != NULL)
            q.push({curr->right, hd + 1});
    }

    for (auto p : mp)
    {
        vector<int> v = p.second;

        for (int x : v)
            cout << x << " ";

        cout << endl;
    }
}

int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->right = new node(50);
    root->left->left = new node(40);

    vertTrav(root);
}
