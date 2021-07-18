#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph {
	map<T, list<T>> adjList;

public:
	void addEdge(T x, T y, bool bidirectional = true) {
		adjList[x].push_back(y);
		if (bidirectional) adjList[y].push_back(x);

	}

	bool isCyclic(T src) {
		map<T, bool> visited;
		map<T, int> parent;
		queue<T> q;

		q.push(src);
		visited[src] = true;
		parent[src] = src;

		while (!q.empty()) {
			T node = q.front();
			q.pop();

			for (T nbr : adjList[node]) {
				if (visited[nbr] and parent[node] != nbr)
					return true;

				else if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
					parent[nbr] = node;
				}
			}
		}
		return false;
	}

};

int main() {
	Graph <int> g;
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(4, 3);
	g.addEdge(2, 3);

	if (g.isCyclic(1)) cout << "Cyclic Graph";
	else cout << "Not cyclic";
}