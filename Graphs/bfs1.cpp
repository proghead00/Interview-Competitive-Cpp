#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	list<int> *l;

public:
	Graph(int V) {
		this->V = V;
		l = new list<int> [V];

	}

	void addEdge(int i, int j, bool undir = true) {
		l[i].push_back(j);
		if (undir) l[j].push_back(i);
	}

	void bfs(int src) {
		queue<int> q;
		bool *visited = new bool[V] {0};

		q.push(src);
		visited[src] = true;

		while (!q.empty()) {
			int f = q.front();
			cout << f << " ";
			q.pop();

			// push neighbours of curr node
			for (auto nbr : l[f]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}


	void bfs_SSSP(int src, int dest = -1) {
		queue<int> q;
		bool *visited = new bool[V] {0};

		int *dist = new int [V] {0};
		int *parent = new int [V];

		memset(parent, -1, sizeof(parent));
		// for (int i = 0; i < V; i++) parent[i] = -1;

		q.push(src);
		visited[src] = true;

		parent[src] = src;
		dist[src] = 0;

		while (!q.empty()) {
			int f = q.front();
			cout << f << " ";
			q.pop();

			// push neighbours of curr node
			for (auto nbr : l[f]) {
				if (!visited[nbr]) {
					q.push(nbr);

					parent[nbr] = f;
					dist[nbr] = dist[f] + 1;

					visited[nbr] = true;
				}
			}
		}

		for (int i = 0; i < V; i++) cout << "Shortest distance to " << i << " is " << dist[i] << endl;

		if (dest != -1) {
			int temp = dest;
			while (temp != src) {
				cout << temp << " -- ";
				temp = parent[temp];
			}
			cout << src << endl;
		}
	}
};

int main() {

	Graph g(7);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(5, 6);
	g.addEdge(4, 5);
	g.addEdge(0, 4);
	g.addEdge(3, 4);

	g.bfs_SSSP(1, 6);

}