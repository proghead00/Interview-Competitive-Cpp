#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {

	map<T, list<T>> adjList;

public:

	void addEdge(T x, T y, bool bidirectional) {
		adjList[x].push_back(y);
		if (bidirectional) adjList[y].push_back(x);
	}

	bool isCycleHelper(T node, map<T, bool>&visited, map<T, bool>&inStack) {

		visited[node] = true;
		inStack[node] = true;
	}

	void isCylic() {
		map<T, bool> visited;
		map<T, bool> inStack;

		// check for cycle in each dfs tree
		for (auto p : adjList) {
			T node = p.first;
			if (!visited[node]) {
				bool cyclePresent = isCycleHelper(node, visited, inStack);
			}
		}
	}
}