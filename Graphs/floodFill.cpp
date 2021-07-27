#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int arr[N][N];

int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void floodFill(int x, int y) {
	arr[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];

		if (newX >= 0 and newX < n and newY >= 0 and newY < m and arr[newX][newY] == 1)
			floodFill(newX, newY);
	}

}


int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				cnt++;
				floodFill(i, j);
			}
		}
	}
	cout << cnt;
}

// 6 5
// 0 0 0 1 1
// 0 1 0 0 0
// 1 1 0 1 0
// 1 0 1 1 1
// 0 0 1 1 0
// 0 0 0 0 0
