#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = 22;

vector<int> graph[N];
int visited[N];

bool oddCycle = 0;

// COLOR:
// 0 -> not visited; 1-> visisted and colored 1; 2-> visited and colored 2

void dfs(int node, int parent, int color) {
	visited[node] = color;

	for (auto nbr : graph[node]) {
		if (visited[nbr] == 0) {
			dfs(nbr, node, 3 - color);
		}

		// backedge and odd length cycle
		else if (node != parent and color == visited[nbr]) {
			oddCycle = 1;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	int ans = 0, cnt = 0, sum = 0;

	while (m--) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1, 0, 1);

	if (oddCycle) cout << "Not Bipartite";
	else cout << "Bipartite";

}