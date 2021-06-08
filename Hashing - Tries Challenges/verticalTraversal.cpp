#include <iostream>
#include <map>
#include <vector>

class node {
public:
	int data;
	node*left;
	node*right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

void verticalTrav(node*root, map<int, vector<int>>&m,  int hd) {
	if (root == NULL) return;

	m[hd].push_back(root->data);

	verticalTrav(root->left, m, hd - 1);
	verticalTrav(root->right, m, hd + 1);
	return;

}

int main() {


	node*root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);

	root->right->left = new node(6);
	root->right->right = new node(7);

	root->right->right->right = new node(9);

	root->left->right->right = new node(8);

	map <int, vector<int>>m;
	int hd = 0;
	verticalTrav(root, m, hd);

	for (auto p : m)
	{
		for (int x : p.second) {
			cout << x << " ";

		}
		cout << endl;
	}


}