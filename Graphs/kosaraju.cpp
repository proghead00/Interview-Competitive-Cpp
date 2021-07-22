#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[], int i, bool *visited, vector<int> &stk) {
	visited[i] = true;

	for (auto nbr : graph[i]) {
		if (!visited[nbr])
			dfs(graph, nbr, visited, stk);
	}

	// function call is complete

	stk.push_back(i);
}

void dfs__2(vector<int> graph[], int i, bool *visited) {
	cout << i << " ";
	visited[i] = true;

	for (auto nbr : graph[i]) {
		if (!visited[nbr])
			dfs__2(graph, nbr, visited);
	}
}

void solve(vector<int> graph[], vector<int> rev_graph[], int N) {

	bool visited[N];
	memset(visited, 0, N);

	vector<int> stk;

	// step 1: store vertices in stk, according to dfs finish time
	for (int i = 0; i < N; i++) {
		// i --> current node
		if (!visited[i]) {
			dfs(graph, i, visited, stk);
		}
	}

	// ordering => stk

	// step 2 : reverse => already done

	// step 3 => DFS according to the ordering in stk:
	memset(visited, 0, N);

	char componentName = 'A';

	for (int x = stk.size() - 1; x >= 0; x--) {
		int node = stk[x];
		if (!visited[node]) {
			// then, there's a component starting from this node
			cout << "Component " << componentName << " --> ";
			dfs__2(rev_graph, node, visited);

			cout << endl;
			componentName++;
		}
	}

}


int main() {
	// N vertices; M edges;

	int N;
	cin >> N;

	// vector stores adjacency list
	vector<int> graph[N];
	vector<int> rev_graph[N];

	int M;
	cin >> M;

	while (M--) {
		// edge is from x to y
		int x, y;
		cin >> x >> y;

		graph[x].push_back(y);
		rev_graph[y].push_back(x);
	}

	solve(graph, rev_graph, N);
}