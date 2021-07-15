#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph {
	unordered_map <T, list <T> > adjList;

public:
	void addEdge(T x, T y, bool bidirectional = true) {
		adjList[x].push_back(y);
		if (bidirectional) adjList[y].push_back(x);
	}

	void dfsHelper(T node, unordered_map<T, bool> &visited) {
		visited[node] = true;
		cout << node << " ";

		for (T nbr : adjList[node]) {
			if (!visited[nbr]) {
				dfsHelper(nbr, visited);
			}
		}
	}


	void dfs(T src) {
		unordered_map<T, bool> visited;

		dfsHelper(src, visited);
	}
};

int main() {

	Graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 4);
	g.addEdge(2, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(3, 4);

	g.dfs(0);

}
