#include <iostream>
using namespace std;

class node {
public:
    // left stores 0, right stores 1
    node*left;
    node*right;

};

class trie {
    node*root;
public:
    trie() {
        root = new node();
    }

    void insert(int n) {
        node*temp = root;
        for (int i = 31; i >= 0; i--) {

            // extracting i-th bit and checking whether it's set or unset
            int bit = (n >> i) & 1;

            if (bit == 0) {
                if (temp->left == NULL)
                    temp->left = new node();

                temp = temp->left;
            }

            else {
                if (temp->right == NULL)
                    temp->right = new node();

                temp = temp->right;
            }
        }
    }

    int helper(int value) {
        node*temp = root;
        int curr_ans = 0;
        for (int j = 31; j >= 0; j--) {

            int bit = (value >> j) & 1;

            if (bit == 0) {
                if (temp->right) {
                    temp = temp->right;
                    curr_ans += (1 << j); //2 to the power j
                }
                else temp = temp->left;
            }

            else {
                if (temp->left)
                {   temp = temp->left;
                    curr_ans += (1 << j);
                }

                else temp = temp->right;

            }
        }
        return curr_ans;
    }

    int max_xor(int *arr, int n) {
        int max_xor = 0;

        for (int i = 0; i < n; i++) {
            int val = arr[i];
            // insert the value in the trie:
            insert(val);
            int curr_xor = helper(val);

            max_xor = max(max_xor, curr_xor);
        }

        return max_xor;
    }

};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    trie t;
    cout << t.max_xor(arr, n) << endl;

}
