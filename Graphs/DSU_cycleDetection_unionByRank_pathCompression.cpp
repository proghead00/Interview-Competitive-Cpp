#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	list <pair<int, int>> edgeList;

public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int u, int v) {
		edgeList.push_back({u, v});
	}

	int findSet(int node, int parent[]) {
		if (parent[node] == -1) return node; // if the node is parent itself (-1)

		// path compression:
		return parent[node] = findSet(parent[node], parent);
	}

	void unionSet(int x, int y, int parent[], int rank[]) {

		// find leaders of set 1 and 2:
		int s1 = findSet(x, parent);
		int s2 = findSet(y, parent);

		// Union by Rank:

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1]; // thus, rank of THAT LEADER becomes the size of that set
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}


	bool containsCycle() {
		int *parent = new int[V];
		int *rank = new int[V];

		for (int i = 0; i < V; i++) {
			parent[i] = -1; // since initially parent of every node is that itself
			rank[i] = 1;
		}

		for (auto edge : edgeList) {
			int i = edge.first;
			int j = edge.second;

			int s1 = findSet(i, parent);
			int s2 = findSet(j, parent);

			if (s1 != s2) unionSet(s1, s2, parent, rank);

			else return true;
		}

		delete[] parent;
		delete[] rank;
		return false;
	}
};

int main() {
	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 0);

	(g.containsCycle()) ? cout << "Cycle's Present" : cout << "Cycle's Not Present";
}