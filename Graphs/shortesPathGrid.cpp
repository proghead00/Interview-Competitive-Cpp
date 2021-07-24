#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> grid) {

	int m = grid.size(); //rows
	int n = grid[0].size(); //cols

	vector<vector<int>> dist(m + 1, vector<int>(n + 1, INT_MAX)); // M+1 ROWS; N+1 COLS

	dist[0][0] = grid[0][0];

	set <vector<int>> ss;
	s.insert({dist[0][0], 0, 0});

	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};

	int i = 0, j = 0;

	while (!s.empty()) {
		auto p = *(s.begin());

		int curr_d = p.frst[0];
		int curr_x = p.first[1];
		int curr_y = p.first[2];

		s.erase(s.begin());

		// update nbrs
		for (int k = 0; k < 4; k++) {

			int newX = curr_x + dx[k];
			int newY = curr_y + dy[k];

			if (newX >= 0 and newX<m and newY >= 0 and newY < n and curr_d + grid[newX][newY] < dist[newX][newY]) {

				auto f = s.find({dist[nx][ny], newX, newY});

				if (f != s.end()) {
					s.erase(f);
				}

				int newDist = grid[newX][newX] + curr_d;
				dist[newX][newY] = newDist;
				s.insert({newDist, newX, newY});
			}
		}
	}
	return dist[m - 1][n - 1];

}

int main() {

}