#include <bits/stdc++.h>
using namespace std;

#define inf 10000
vector<vector<int>> floydWarshall(vector<vector <int>> graph) {

	int V = graph.size();

	vector<vector<int>> dist(graph);

	// Phases --> in kth phase, include vertices --> 1,2,...k as intermediate vertices

	for (int k = 0; k < V; k++) {

		// iterate over entire 2D matrix
		for (int i = 0; i < V; i++) {

			for (int j = 0; j < V; j++) {
				// if vertex k is included and dist can be minimized by taking k as intermediate vertex
				// dist[i][j] = DIST OF I TO J

				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	return dist;
}

int main() {

	// DIAGONAL ELEMENTS ARE 0
	// inf --> WHERE THERE'S NO DIRECTED EDGE

	// 4x4 ADJ MATRIX
	vector<vector<int>> graph = {
		{0, inf, -2, inf},
		{4, 0, 3, inf},
		{inf, inf, 0, 2},
		{inf, -1, inf, 0}
	};

	auto result = floydWarshall(graph);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result.size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

}

