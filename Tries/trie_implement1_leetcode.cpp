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
			if (!temp->mp.count(w)) {
				Node* n = new Node(w);
				temp->mp[w] = n;
			}

			temp = temp->mp[w];
		}

		temp->isTerminal = true;
	}

	bool search(string word) {
		Node* temp = root;

		for (char w : word) {
			if (!temp->mp.count(w)) return false;

			temp = temp->mp[w];
		}

		return temp->isTerminal;
	}

	bool startsWith(string prefix) {
		Node* temp = root;

		for (char w : prefix) {
			if (!temp->mp.count(w)) return false;

			temp = temp->mp[w];
		}

		return true;
	}
};
