#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
};

int sumOfNodesAtNthLevel(struct node *root, int k)
{

    if (root == nullptr)
        return 0;

    queue<struct node *> que;

    que.push(root);

    // Level is used to track
    // the current level
    int level = 0;

    int sum = 0;

    int flag = 0;

    while (!que.empty())
    {

        int size = que.size();

        while (size--)
        {

            struct node *ptr = que.front();
            que.pop();

            if (level == k)
            {

                flag = 1;

                sum += ptr->data;
            }
            else
            {

                if (ptr->left)
                    que.push(ptr->left);

                if (ptr->right)
                    que.push(ptr->right);
            }
        }

        level++;

        // Break out from the loop after the sum
        // of nodes at K level is found
        if (flag == 1)
            break;
    }
    return sum;
}

int main()
{
    struct node *root = new struct node;

    root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    int level = 2;
    int result = sumOfNodesAtNthLevel(root, level);

    cout << result;

    return 0;
}
