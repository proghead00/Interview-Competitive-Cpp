#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	char data;
	unordered_map<char, Node*> mp;

	Node(char d) {
		data = d;
	}
};

int countDistinctSubstrings(string word) {
	Node* root = new Node('\0');
	int cnt = 0;
	for (int i = 0; i < word.size(); i++) {
		Node* temp = root;
		for (int j = i; j < word.size(); j++) {
			if (temp->mp.count(word[j]) == 0) {
				Node* n = new Node(word[j]);
				temp->mp[word[j]] = n;
				cnt++;
			}
			temp = temp->mp[word[j]];
		}
	}
	return cnt + 1;
}
