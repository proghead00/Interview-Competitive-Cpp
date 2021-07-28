#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> adjList[N];
int vis[N];
bool cycle = false;

// 3 states => 0, 1, 2

//  	1
// 	  /	  \
// 	3 ---- 2

void dfs(int node, int parent) {

	// visited and in call stack ==> 1
	vis[node] = 1;

	for (auto nbr : adjList[node]) {

		if (!vis[nbr]) {
			dfs(nbr, node);
		}

		else if (nbr != parent and vis[nbr] == 1) {
			// backedge
			cycle = true;

			cout << node << " --> " << nbr << endl;
		}
	}

	// visited and not in call stack
	vis[node] = 2;

	// return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i, 0);
		}
	}

	if (cycle)
		cout << "Cycle's found";

	else
		cout << "Cycle's not found";


	return 0;
}