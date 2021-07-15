#include <iostream>
#include <map>
#include <list>
#include <climits>
#include <queue>
using namespace std;

template<typename T>

class Graph {
	map<T, list<T>> adjList;

public:
	void addEdge(T x, T y, bool bidirectional = true) {
		adjList[x].push_back(y);
		if (bidirectional) adjList[y].push_back(x);
	}

	int bfs_SSSP(T src, T dest) {
		map<T, int> dist;
		map<T, T> parent;

		queue<T> q;

		// initialise every other node with inf
		for (auto p : adjList) dist[p.first] = INT_MAX;

		// push src as first
		q.push(src);
		dist[src] = 0;
		parent[src] = src;

		while (!q.empty()) {

			T node = q.front();
			// cout << node << " ";
			q.pop();

			for (T nbr : adjList[node]) {
				if (dist[nbr] == INT_MAX) {
					q.push(nbr);

					dist[nbr] = dist[node] + 1;
					parent[nbr] = node;
				}
			}
		}

		T temp = dest;
		while (temp != src) {
			cout << temp << " <-- ";
			temp = parent[temp];
		}
		cout << src << endl;
		return dist[dest];
	}


};

int main() {

	Graph<int> g;
	int board[50] = {0};
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;

	for (int u = 0; u <= 36 ; u++) {
		// at every node we can throw a die
		for (int dice = 1; dice <= 6; dice++) {
			int v = u + dice + board[u + dice];

			g.addEdge(u, v, false);
		}
	}

	cout << "Distance: " << g.bfs_SSSP(1, 36);
}

