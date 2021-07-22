#include <bits/stdc++.h>
using namespace std;

struct node {
	int u;
	int v;
	int wt;
	node(int first, int second, int weight) {
		u = first;
		v = second;
		wt = weight;
	}
};

bool comp(node a, node b) {
	return a.wt < b.wt;
}

int findParent(int node, vector<int> &parent) {
	if (node == parent[node]) return node;
	return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
	int s1 = findParent(u, parent);
	int s2 = findParent(s2, parent);

	if (rank[s1] < rank[s2]) parent[s1] = s2;

	else if (rank[s2] < rank[s1]) parent[s2] = s1;

	else {
		parent[s2] = s1;
		rank[s1]++;
	}
}


int main() {
	int N, m;
	cin >> N >> m;

	vector<node> edges;

	for (int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back(node(u, v, wt));
	}

	sort(edges.begin(), edges.end(), comp);

	vector<int> parent(N);

	for (int i = 0; i < N; i++)	parent[i] = i;

	vector<int> rank(N, 0);

	int cost = 0;

	vector<pair<int, int>> mst;

	for (auto it : edges) {
		if (findParent(it.v, parent) != findParent(it.u, parent)) {
			cost += it.wt;
			mst.push_back({it.u, it.v});
			unionn(it.u, it.v, parent, rank);
		}
	}
	cout << cost << endl;
	for (auto it : mst) cout << it.first << " - " << it.second << endl;
	return 0;
}
