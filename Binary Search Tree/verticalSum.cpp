#include <iostream>
#include <map>
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

// HD = HORIZONTAL DISTANCE
void sumRec(node *root, int hd, map<int, int> &mp)
{

    if (root == NULL)
        return;

    sumRec(root->left, hd - 1,  mp);

    mp[hd] += root->data;

    sumRec(root->right, hd + 1,  mp);
}

void sum(node *root)
{
    map<int, int> mp;
    sumRec(root, 0,  mp);

    for (auto sum : mp)
    {
        cout << sum.second << " ";
    }
}

int main(){
    node*root = new node(10);
    root->left = new node(20);
    root->right = new node(50);

    root->left->right = new node(40);
    root->left->left = new node(30);

    sum(root);
}
