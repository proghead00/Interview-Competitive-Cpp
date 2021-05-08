#include <iostream>
#include <limits.h>
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



// For each node there can be four ways that the max path goes through the node:
// 1. Node only
// 2. Max path through Left Child + Node
// 3. Max path through Right Child + Node
// 4. Max path through Left Child + Node + Max path through Right Child

int utilFn(node *root, int &ans)
{
    if (root == NULL)
        return 0;

    int left = utilFn(root->left, ans);
    int right = utilFn(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right),
                      max(root->data + left, root->data + right));

    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data, max(root->data + left, root->data + right));
    return singlePathSum;
}

int maxPathSum(node *root)
{
    int ans = INT_MIN;
    utilFn(root, ans);
    return ans;
}

// int max_sum = INT_MIN;
// int maxPathSum(node *root)
// {
//     // base
//     if (root == NULL)
//         return INT_MIN;

//     int left_sum = maxPathSum(root->left);
//     int right_sum = maxPathSum(root->right);

//     int ans = root->data;

//     if (left_sum > 0)
//         ans += left_sum;
//     if (right_sum > 0)
//         ans += right_sum;

//     max_sum = max(max_sum, ans);

//     return root->data + max(0, max(left_sum, right_sum));
// }

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);

    cout << "O/p: " << maxPathSum(root);
}
