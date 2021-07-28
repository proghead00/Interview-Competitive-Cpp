#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

// int arr[N][N];

const int r = 4, c = 4;

// int arr[r][c] = {
// 	{1, 0, 0, 1, 0},
// 	{1, 0, 1, 0, 0},
// 	{0, 0, 1, 0, 1},
// 	{1, 0, 1, 1, 1},
// 	{1, 0, 1, 1, 0}
// };
int arr[r][c] = {
	{1, 1, 1, 0},
	{1, 0, 0, 1},
	{0, 1, 1, 1},
	{1, 1, 0, 0}
};

int visited[N][N];


unordered_map<int, int> mp;

// -----------------------------------------------
void ff(int x, int y, int &island__ID) {
	arr[x][y] = island__ID;
	visited[x][y] = true;

	mp[island__ID]++;

	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};

	for (int k = 0; k < 4; k++) {
		int xx = x + dx[k];
		int yy = y + dy[k];

		if (xx >= 0 and xx<r and yy >= 0 and yy < c and !visited[xx][yy] and arr[xx][yy] == 1) {
			ff(xx, yy, island__ID);
		}
	}
}

int main() {

	int island__ID = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 1 and !visited[i][j]) {
				island__ID++;
				ff(i, j, island__ID);
			}
		}
	}

	int largest = -1;
	for (auto p : mp) {
		largest = max(largest, p.second);
	}
	cout << largest;
	// for (auto x : mp) cout << x.first << "-->" << x.second << " " << endl;

}