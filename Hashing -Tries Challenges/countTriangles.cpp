#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int count_triangles(vector<pair<int, int>> &points) {
	unordered_map<int, int>freqX;
	unordered_map<int, int>freqY;

	// frequencies
	for (auto p : points) {
		int x = p.first;
		int y = p.second;

		freqX[x]++;
		freqY[y]++;
	}

	int cnt = 0;
	for (auto p : points) {
		int x = p.first;
		int y = p.second;

		int fx = freqX[x];
		int fy = freqY[y];

		cnt += (fx - 1) * (fy - 1); // excluding the pivot
	}
	return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; // no of points
	cin >> n;

	vector<pair<int, int>> points;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		points.push_back({x, y});
	}
	cout << count_triangles(points);
}