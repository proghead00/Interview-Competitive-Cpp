#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> adjList[N];

bool dfs(int node, vector<bool> &visited, vector<bool> &inStack) {

	visited[node] = true;
	inStack[node] = true;

	for (auto nbr : adjList[node]) {

		if (inStack[nbr]) return true;

		else if (!visited[nbr]) {
			bool cycle = dfs(nbr, visited, inStack);
			if (cycle) return true;
		}
	}

	inStack[node] = false;
	return false;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		adjList[x].push_back(y);
		// adjList[y].push_back(x);
	}

	vector<bool> visited(n, false);
	vector<bool> inStack(n, false);

	bool cycle = false;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			if (dfs(i, visited, inStack)) {
				cycle = true;
				break;
			}

		}
	}

	if (cycle) cout << "Cycle's Present";
	else cout << "Not present";


}