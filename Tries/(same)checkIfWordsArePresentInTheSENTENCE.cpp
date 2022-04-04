#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	char data;
	bool isTerminal;
	unordered_map<char, Node*> mp;
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

	void insert(string words) {
		Node* temp = root;
		for (auto w : words) {
			if (!temp->mp.count(w)) {
				Node* n = new Node(w);
				temp->mp[w] = n;
			}

			temp = temp->mp[w];
		}

		temp->isTerminal = true;
	}

	void srchHelper(string s, int i, unordered_map<string, bool> &srchMp) {
		Node* temp = root;

		for (int j = i; j < s.size(); j++) {
			char ch = s[j];

			if (!temp->mp.count(ch)) return;

			temp = temp->mp[ch];

			if (temp->isTerminal) {
				string part = s.substr(i, j - i + 1);
				srchMp[part] = true;
			}
		}

		return;
	}

	void search(string s, vector<string> words) {

		for (auto w : words) insert(w);

		unordered_map<string, bool> srchMp;

		for (int i = 0; i < s.size(); i++) {
			srchHelper(s, i, srchMp);
		}

		for (auto w : words) {
			if (srchMp[w]) cout << w << ": YES";
			else cout << w << " NO";
			cout << endl;

		}

		return;

	}

};


int main() {
	string s = "little cute cat loves";
	vector<string> words = {"cute cat", "ttle", "kek"};
	Trie t;
	t.search(s, words);
	return 0;
}
