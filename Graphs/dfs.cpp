#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph {
	map <T, list <T> > adjList;

public:
	void addEdge(T x, T y, bool bidirectional = true) {
		adjList[x].push_back(y);
		if (bidirectional) adjList[y].push_back(x);
	}

// ----------------------------------------------------------------------------------
	void dfsHelper(T node, map<T, bool> &visited) {
		cout << node << " ";
		visited[node] = true;

		// go to all neighbours of that node one by one
		for (T nbr : adjList[node]) {
			if (!visited[nbr]) {
				dfsHelper(nbr, visited);
			}
		}
	}

// ----------------------------------------------------------------------------------

	void dfs(T src) {
		map<T, bool> visited;

		// no need to initialise FALSE in map, since it already is

		dfsHelper(src, visited);
	}

// ----------------------------------------------------------------------------------

	void dfs_connectedComponents() {
		map<T, bool> visited;

		// mark all nodes as not visited at the beginning
		for (auto p : adjList) {
			T node = p.first;
			visited[node] = false;
		}

		int c = 0;
		for (auto p : adjList) {
			T node = p.first;

			if (!visited[node]) {
				cout << "Component " << c << " --> ";
				dfsHelper(node, visited);
				c++;
				cout << endl;

			}
		}
	}


};

int main() {

	Graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 3);
	g.addEdge(0, 4);

	g.addEdge(5, 6);
	g.addEdge(6, 7);

	g.addEdge(8, 8);


	g.dfs(0);
	cout << endl;

	g.dfs_connectedComponents();

}
