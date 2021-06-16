#include <iostream>
using namespace std;

// only 2 bottles can be sold
int profit_topDown(int wines[], int i, int j, int y) {

	if (i > j) return 0;

	int op1 = wines[i] * y + profit_topDown(wines, i + 1, j, y + 1 );
	int op2 = wines[j] * y + profit_topDown(wines, i, j - 1, y + 1 );

	return max(op1, op2);

}

int profit_bottomUp(int wines[], int i, int j, int y, int dp[][100]) {
	if (i > j) return 0;

	if (dp[i][j] != 0) return dp[i][j];

	int op1 = wines[i] * y + profit_bottomUp(wines, i + 1, j, y + 1, dp );
	int op2 = wines[j] * y + profit_bottomUp(wines, i, j - 1, y + 1, dp );

	return dp[i][j] = max(op1, op2);
}



int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int wines[] = {2, 3, 5, 1, 4};

	int dp[100][100] = {0};
	int n = sizeof(wines) / sizeof(int);
	int y = 1;

	cout << profit_topDown(wines, 0, n - 1, y) << endl;
	cout << profit_bottomUp(wines, 0, n - 1, y, dp);
}