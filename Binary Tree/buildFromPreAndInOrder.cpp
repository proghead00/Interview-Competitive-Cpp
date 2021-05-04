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

node *buildTreeFromPreIn(int *in, int *pre, int s, int e)

{                      // taking a global/static variable since we don't need backtracking, we need to have the same value of this variable after every call
    static int gi = 0; // denoting from which index we're gonna pick the node

    // base case
    if (s > e)
        return NULL;

    node *root = new node(pre[gi]);

    int idx = -1;
    for (size_t j = s; j <= e; j++)
    {
        if (in[j] == pre[gi])
        {
            idx = j;
            break;
        }
    }

    gi++;

    root->left = buildTreeFromPreIn(in, pre, s, idx - 1);
    root->right = buildTreeFromPreIn(in, pre, idx + 1, e);
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
    int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int n = sizeof(in) / sizeof(int);

    node *root = buildTreeFromPreIn(in, pre, 0, n - 1);

    bfs_lineByLine(root);
}
