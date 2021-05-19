#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
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

void bottomView(node *root)
{

    queue<pair<node *, int>> q; // node, hd  --> take out curr node and hd
    q.push({root, 0});

    map<int, vector<int>> mp;

    while (!q.empty())
    {
        auto f = q.front();

        node *curr = f.first;
        int hd = f.second;

        if (!mp.count(hd))
            mp[hd].push_back(curr->data);

        else
        {
            for (auto p : mp)
            {
                vector<int> v = p.second;

                replace(p.second.begin(), p.second.end(), 1, v[hd]);
            }
        }
        // mp[hd].push_back(curr->data);
        q.pop();

        if (curr->left)
            q.push({curr->left, hd - 1});

        if (curr->right)
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
    root->left->left = new node(40);
    root->right->left = new node(60);
    root->left->right = new node(50);

    bottomView(root);
}
