class LRUCache {
public:
	list<pair<int, int>> lru;
    
    // iterator will store the respective address
	unordered_map<int, list<pair<int, int>>::iterator> mp; // {key, address} pair

	void updatePosition(int key, int value) {
		lru.erase(mp[key]);
		lru.push_front({key, value});
		mp[key] = lru.begin();     // address of new position stored in the map
	}

	int capacity;
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if (mp.find(key) != mp.end()) {
			updatePosition(key, (*mp[key]).second);
			return (*mp[key]).second;
		}
		return -1;
	}

	void put(int key, int value) {
		if (mp.find(key) != mp.end()) updatePosition(key, value);
		else {
			// add to cache
			lru.push_front({key, value });
			mp[key] = lru.begin();

			if (mp.size() > capacity) {
				mp.erase(lru.back().first);
				lru.pop_back();
			}
		}
	}
};

 
