#include <iostream>
using namespace std;

class node {
public:
	// left stores 0, right stores 1
	node*left;
	node*right;
	vector<int> v;
};

class trie {
	node*root;
public:
	trie() {
		root = new node();
	}

	void insert(int n, int index) {
		node*temp = root;
		for (int i = 31; i >= 0; i--) {

			// extracting i-th bit and checking whether it's set or unset
			int bit = (n >> i) & 1;

			if (bit == 0) {
				if (temp->left == NULL)
					temp->left = new node();

				temp->v.push_back(index);
				temp = temp->left;
			}

			else {
				if (temp->right == NULL)
					temp->right = new node();

				temp->v.push_back(index);
				temp = temp->right;
			}
		}
		temp->v.push_back(index);
	}

	bool binarysearchrange(vector<int>v, int left , int right) {
		int l = 0;
		int h = v.size() - 1;
		while (l <= h) {

			int m = (l + h) / 2;
			int val = v[m];
			if (val >= left && val <= right) {
				return true;
			}
			else if (val < left) {
				l = m + 1;
			}
			else if (val > right) {
				h = m - 1;
			}

		}
		return false;
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
				{	temp = temp->left;
					curr_ans += (1 << j);
				}

				else temp = temp->right;

			}
		}
		return curr_ans;
	}

	int max_xor(int *arr, int n, int left, int right) {
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
	trie t;
	int q;
	cin >> q;
	int index = 0;
	while (q--) {

		int type;
		cin >> type;

		if (q == 0) {
			int val;
			cin >> val;
			insert(val, index);
			index++;
		}
		else if (q == 1) {
			int x, l, r;
			cin >> l >> r >> x;
			cout << max_xor( x, l - 1, r - 1);
		}
	}
	return 0;

}
