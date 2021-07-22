#include <bits/stdc++.h>
using namespace std;

class dsu {
	int *parent;
	int *ranks;

public:
	dsu(int n) {
		parent = new int[n];
		ranks = new int[n];

		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			ranks[i] = 1;
		}
	}

	int findSet(int node) {
		if (parent[node] == -1) return node;

		return parent[node] = findSet(parent[node]);
	}

	void unite(int x, int y) {
		int s1 = findSet(x);
		int s2 = findSet(y);

		if (s1 != s2) {

			if (ranks[s1] < ranks[s2]) {
				parent[s1] = s2;
				ranks[s2] += ranks[s1];
			}
			else {
				parent[s2] = s1;
				ranks[s1] += ranks[s2];
			}
		}
	}

};

class Graph {
	vector<vector<int>> edgeList;
	int V;

public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int x, int y, int w) {
		// edge is from x to y
		edgeList.push_back({w, x, y});
	}

	int kruskal_MST() {
		dsu s(V);

		sort(edgeList.begin(), edgeList.end());

		int ans = 0;
		for (auto edge : edgeList) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			// take that edge in MST if it doesn't form a cycle
			if (s.findSet(x) != s.findSet(y)) {
				s.unite(x, y);
				ans += w;
			}
		}
		return ans;
	}
};

int main() {
	// Graph g(4);

	// g.addEdge(0, 1, 1);
	// g.addEdge(1, 3, 3);
	// g.addEdge(3, 2, 4);
	// g.addEdge(2, 0, 2);
	// g.addEdge(0, 3, 2);
	// g.addEdge(1, 2, 2);

	// For SPOJ MST:
	int n, m;
	cin >> n >> m;
	Graph g(n);

	while (m--) {
		int x, y, w;
		cin >> x >> y >> w;
		g.addEdge(x - 1, y - 1, w);
	}

	cout << g.kruskal_MST() << endl;
}