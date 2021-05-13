#include <iostream>
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

bool isSame(node *a, node *b)
{
    // 1. both empty
    if (a == NULL && b == NULL)
        return true;

    // 2. both non-empty -> compare them
    if (a != NULL && b != NULL)
    {
        return (
            isSame(a->left, b->left) and
            isSame(a->right, b->right));
    }

    // 3. one empty, one not -> false
    return 0;
}

int main()
{
    node *root1 = new node(10);
    node *root2 = new node(100);
    root1->left = new node(7);
    root1->right = new node(15);
    root1->left->left = new node(4);
    root1->left->right = new node(9);
    root1->right->right = new node(20);

    root2->left = new node(70);
    root2->right = new node(150);
    root2->left->left = new node(40);
    root2->left->right = new node(90);
    root2->right->right = new node(200);

    if (isSame(root1, root2))
        printf("Yes");
    else
        printf("No");
}
