#include <iostream>
#include <unordered_map>
using namespace std;


class Node {
public:
	char data;
	unordered_map<char, Node*> mp;
	bool isTerminal;

	int endsWith = 0;
	int prefix = 0;

	Node(char d) {
		data = d;
		isTerminal = false;
	}
};

class Trie {

public:

	Node* root;
	Trie() {
		// Write your code here.
		root = new Node('\0');
	}

	void insert(string &word) {
		// Write your code here.

		Node* temp = root;
		for (char w : word) {
			if (temp->mp.count(w) == 0) {
				Node *n = new Node(w);
				temp->mp[w] = n;
			}
			temp = temp->mp[w];
			temp->prefix++;

		}

		temp->endsWith++;
		temp->isTerminal = true;

	}

	int countWordsEqualTo(string &word) {
		// Write your code here.
		Node* temp = root;

		for (char w : word) {

			if (temp->mp.count(w)) temp = temp->mp[w];

			else return 0;

		}

		return temp->endsWith;
	}


	int countWordsStartingWith(string &word) {
		// Write your code here.
		Node* temp = root;

		for (char w : word) {
			if (temp->mp.count(w)) temp = temp->mp[w];
			else return 0;

		}

		return temp->prefix;
	}

	void erase(string &word) {
		// Write your code here.
		Node* temp =  root;
		for (char w : word) {
			if (temp->mp.count(w)) {
				temp = temp->mp[w];
				temp->prefix--;
			}
			else return;
		}

		temp->endsWith--;
	}

};

int main() {

	string words[] = {"apple", "ape", "no", "news", "not", "never"};
	Trie t;

	for (auto w : words) t.insert(w);

	int q;
	cin >> q;

	string searchWord;
	while (q--) {

		cin >> searchWord;
		cout << t.countWordsEqualTo(searchWord);
	}
}
