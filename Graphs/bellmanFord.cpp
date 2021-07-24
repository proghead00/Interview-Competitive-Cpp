#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, int src, vector<vector<int>> edgeList) {

	vector<int> dist(V + 1, INT_MAX); // V+1 --> cuz nodes are numbered from 1 to n
	dist[src] = 0;

	// relax all edges V-1 times
	for (int i = 0; i < V - 1; i++) {
		for (auto edge : edgeList) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];

			if (dist[u] != INT_MAX and dist[u] + wt < dist[v])
				dist[v] = dist[u] + wt;
		}
	}
	// negative wt cycle:
	for (auto edge : edgeList) {
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];

		if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
			cout << "Negative weight cycle's found";
			exit(0);
		}
	}

	return dist;
}


int main() {

	int n, m; // n vertices; m edges
	cin >> n >> m;

	vector <vector<int>> edgeList;

	for (int i = 0; i < m; i++) {
		int u, v, wt;

		cin >> u >> v >> wt;

		edgeList.push_back({u, v, wt});
	}

	vector<int> distances = bellmanFord(n, 1, edgeList);

	for (int i = 1; i <= n; i++)
		cout << i << " --> " << distances[i] << endl;

}