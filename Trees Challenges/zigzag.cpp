#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

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

vector<int> zigzag(node *root)
{
    queue<node *> q;
    q.push(root);
    vector<int> ans;

    int f = 1;
    while (!q.empty())
    {
        vector<int> temp;
        int sz = q.size();

        while (sz--)
        {
            node *t = q.front();
            temp.push_back(t->data);
            q.pop();

            if (t->left)
            {
                q.push(t->left);
            }

            if (t->right)
            {
                q.push(t->right);
            }
        }

        if (f % 2 == 0)
            reverse(temp.begin(), temp.end());

        for (size_t i = 0; i < temp.size(); i++)
        {
            ans.push_back(temp[i]);
        }
        f = !f;
    }

    return ans;
}

int main()
{
    node *root = new node(2);
    root->left = new node(1);
    root->right = new node(3);
    root->right->left = new node(4);
    root->left->right = new node(5);

    vector<int> v = zigzag(root);
    for (int x : v)
    {
        cout << x << " ";
    }
}
