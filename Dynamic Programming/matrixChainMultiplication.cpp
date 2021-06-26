#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

// top down
int tdp[100][100];
int matrixChain_topDown(int m[], int i, int j) {

	if (i + 1 == j) {
		tdp[i][j] = 0;
		return 0;
	}

	if (tdp[i][j] != -1) return tdp[i][j];

	int ans = INT_MAX;

	for (int k = i + 1; k < j; k++) {
		int temp = matrixChain_topDown(m, i, k) + matrixChain_topDown(m, k, j) + m[i] * m[k] * m[j];
		ans = min(ans, temp);
	}


	return tdp[i][j] = ans;
}

// bottom up
int matrixChain_bottomUp(int  m[], int n) {
	int dp[n][n];

	for (int i = 0; i < n - 1; ++i) {
		dp[i][i + 1] = 0; // gap of 1 is filled with 0
	}

	for (int gap = 2; gap < n; gap++) {
		for (int i = 0; i + gap < n; i++) {
			int j = i + gap;

			dp[i][j] = INT_MAX;

			for (int k = i + 1; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + m[i] * m[k] * m[j]);

			}
		}

	}
	return dp[0][n - 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int matrices[] = {1, 2, 3, 4}; // dimensions

	int n = sizeof(matrices) / sizeof(int);
	memset(tdp, -1, sizeof tdp);

	cout << matrixChain_topDown(matrices, 0, n - 1) << endl;
	cout << matrixChain_bottomUp(matrices, n) << endl;
}
