#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int arr[N][N], vis[N][N];
int colorCnt[N]; // to map how many colors have how many islands

int n, m;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void floodFill(int x, int y, int color) {
	arr[x][y] = color;
	vis[x][y] = 1;
	colorCnt[color]++;

	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];

		if (newX >= 0 and newX < n and newY >= 0 and newY < m and !vis[newX][newY] and arr[newX][newY] == 1) {
			floodFill(newX, newY, color);
		}
	}
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int totalCount = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 and !vis[i][j]) {
				totalCount++;
				floodFill(i, j, totalCount);
			}
		}
	}
	//--------------------
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}


	cout << endl;

	for (int i = 1; i <= totalCount; i++) {
		cout << i << " --> " << colorCnt[i] << '\n';
	}

	return 0;
}

// 6 5
// 0 0 0 1 1
// 0 1 0 0 0
// 1 1 0 1 0
// 1 0 1 1 1
// 0 0 1 1 0
// 0 0 0 0 0
