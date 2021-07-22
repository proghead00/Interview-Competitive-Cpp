#include <bits/stdc++.h>
using namespace std;

// ADJ LIST --> (NODE, WT)
// PRIORITY Q --> (WT, NODE)

// -----------------------------------------
class Graph {

	// adjacency list:
	// 1 -> (a, w1) (b,w2)...
	// 2 -> (a, w1) (b,w2)...
	vector<pair<int, int>> *adjList;
	int V;

public:
	Graph(int n) {
		V = n;
		adjList = new vector<pair<int, int>> [n];

	}

	void addEdge(int x, int y, int w) {
		adjList[x].push_back({y, w});
		adjList[y].push_back({x, w});
	}

	int prim_MST() {

		// priority_queue < pair<int, int>, vector< pair <int , int> >, greater < pair <int, int> () > > Q; ==> WRONG STATEMENT
		priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > Q;

		bool *visited = new bool[V] {0};
		int ans = 0;

		Q.push({0, 0});  // first -> wt || second -> node's value

		while (!Q.empty()) {

			// pick out edge w/ min weight => bestEdge
			auto bestEdge = Q.top();

			Q.pop();

			// to ==> node to which the edge is directed to
			int to = bestEdge.second;

			int weight = bestEdge.first;

			if (visited[to]) {
				// discard the edge since it's not an active edge
				continue;
			}

			// else, take the current edge
			ans += weight;
			visited[to] = true;

			// add the new adjacent edges
			for (auto x : adjList[to]) {
				if (!visited[x.first]) {
					Q.push({x.second, x.first});
				}
			}
		}
		return ans;
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	Graph g(n);

	while (m--) {
		int x, y, w;
		cin >> x >> y >> w;

		g.addEdge(x - 1, y - 1, w);
	}

	cout << g.prim_MST() << endl;
}