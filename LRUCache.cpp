#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	string key;
	int value;

	Node(string key, int value) {
		this->key = key;
		this->value = value;
	}
};

class LRU {
public:
	int maxSize;
	list<Node> l;
	unordered_map<string, list<Node>::iterator> mp; // it is an iterator to the node that's in the list

	LRU(int maxSize) {
		this->maxSize = maxSize > 1 ? maxSize : 1; // if maxSize == 0, set it to 1 (minimum of 1 is needed)
	}

	void insert(string key, int value) {
		if (mp.count(key)) {
			// update the key
			auto it = mp[key];
			it->value = value;
		}
		else {
			// check if cache is full
			// if yes, remove LRU item from the cache

			if (l.size() == maxSize) {
				Node last = l.back();
				mp.erase(last.key);
				l.pop_back();
			}

			Node n(key, value);
			l.push_front(n);
			mp[key] = l.begin();
		}
	}

	int* getValue(string key) {
		if (mp.count(key)) {
			auto it = mp[key];
			int value = it->value;
			l.push_front(*it);
			l.erase(it);
			mp[key] = l.begin();

			return &l.begin()->value;
		}

		return NULL;
	}

	string mostRecentKey() {
		return l.front().key;
	}
};

int main() {
	int mx; cin >> mx;
	LRU lru(3);
	lru.insert("Pen Drive", 10);
	lru.insert("TWS", 20);
	lru.insert("Smartwatch", 30);
	cout << lru.mostRecentKey() << endl;

	lru.insert("Pen Drive", 40);
	cout << lru.mostRecentKey() << endl;

	lru.insert("SSD", 20);
	cout << lru.mostRecentKey() << endl;

	if (!lru.getValue("TWS")) cout << "TWS is not present";
	if (!lru.getValue("Smartwatch")) cout << "Smartwatch is not present";
	if (!lru.getValue("Pen Drive")) cout << "Pen Drive is not present";

}
