#include <iostream>
using namespace std;

class node
{
public:
    // if the left ptr is not NULL -> we have a zero
    // if the right ptr is not NULL -> we have a one in the right
    node *left;  // 0
    node *right; // 1
};

class trie
{
    node *root;

public:
    trie()
    {
        root = new node();
    }

    void insert(int n)
    {
        // insert bits of the number in the trie (32 bits)

        node *temp = root;
        // i starts with the MSB
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1; // extracting each bit from left (i.e from MSB)

            if (bit == 0)
            {
                if (temp->left == NULL)
                {
                    temp->left = new node();
                }

                // go to that node everytime
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                    temp->right = new node();
                temp = temp->right;
            }
        }
    }

    int max_XOR_helper(int value)
    {
        int currentAns = 0;
        node *temp = root;

        // will look for 0 if we have 1 in the curr bit and vice versa
        for (int j = 31; j >= 0; j--)
        {
            int bit = (value >> j) & 1;

            if (bit == 0)
            {

                // find the opposite value
                if (temp->right != NULL)
                {
                    temp = temp->right;
                    currentAns += (1 << j); // power(2,j)
                }
                else
                {
                    temp = temp->left;
                }
            }

            else // if the curr bit is 1 -> look for a zero
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                    currentAns += (1 << j);
                }
                else // if there's no zero
                {
                    temp = temp->right;
                }
            }

            return currentAns;
        }
    }

    int max_XOR(int *input, int n)
    {
        int max_xor = 0;

        for (int i = 0; i < n; i++)
        {
            int value = input[i];
            insert(value);
            int curr_xor = max_XOR_helper(value);
            max_xor = max(curr_xor, max_xor);
        }
        return max_xor;
    }
};

int main()
{
    int input[] = {3, 10, 5, 25, 9, 2};
    int n = sizeof(input) / sizeof(int);

    trie t;
    cout << t.max_XOR(input, n) << endl;
}
