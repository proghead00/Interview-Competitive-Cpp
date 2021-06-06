#include <iostream>
#include <map>
using namespace std;

class node {
public:
	char data;
	map<char, node*> children;
	bool isTerminal;

	node(char d) {
		data = d;
		isTerminal = false;
	}
};

class trie {
public:
	node*root ;

	trie() {
		root = new node('\0');
	}

	void insert(string word) {

		for (char ch : word) {
			if (temp->children.count(ch) == 0)
			{
				node*n = new node(ch);
				temp->children[ch] = n; // store the address of this node in the hashmap, corresponding to the key given by ch
				temp = n;

			}
			else {
				temp = temp->children[ch];
			}
		}
		temp-> isTerminal = true;
	}

	void print(node *temp, string word)
	{
		if (temp->h.empty())
		{
			cout << word << endl;
			return;
		}
		if (temp->isterminal)
		{
			cout << word << endl;
		}
		node *t;
		string w;
		for (auto it = temp->h.begin(); it != temp->h.end(); it++)
		{
			t = temp->h[it->first];
			w = word + it->first;
			print(t, w);
		}
		return;
	}

	bool search(string word)
	{
		node *temp = root;
		char ch;
		for (int i = 0; word[i] != '\0'; i++)
		{
			ch = word[i];
			if (temp->h.count(ch))
			{
				temp = temp->h[ch];
			}
			else
			{
				return false;
			}
		}
		print(temp, word);
		return true;
	}

};