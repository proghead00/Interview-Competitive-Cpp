#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	char data;
	unordered_map<char, Node*> mp;
	bool isTerminal;

	Node(char d) {
		data = d;
		isTerminal = false;
	}
};

class Trie {
public:

	Node* root;

	Trie() {
		root = new Node('\0');
	}

	void insert(string word) {

		Node* temp = root;

		for (char w : word) {
			if (temp->mp.count(w) == 0) {
				Node* n = new Node(w);
				temp->mp[w] = n;
			}
			temp = temp->mp[w];
		}

		temp-> isTerminal = true;
	}

	bool check(string word) {
		Node *temp = root;
		for (char w : word) {
			if (temp->mp.count(w)) {
				temp = temp->mp[w];
				if (!temp->isTerminal) return false;
			}
			else return false;
		}
		return true;
	}

	string completeString(int n, vector<string> &a) {
		for (string word : a) insert(word);

		string res = "";

		for (string word : a) {
			if (check(word)) {
				if (word.size() > res.size()) res = word;
				else if (word.size() == res.size() and word < res) 	res = word;
			}
		}
		if (res == "") return "None";
		return res;
	}
};


int main() {
	vector<string> words = {"ab", "bc"};
	Trie t;
	cout << t.completeString(4, words);
	return 0;
}
