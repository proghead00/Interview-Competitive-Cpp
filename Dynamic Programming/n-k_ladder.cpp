#include <iostream>
#include <vector>
using namespace std;

int ways_topDown(int n, int k, int *dp) {
	if (n == 0) return 1;

	if (n < 0) return 0;

	if (dp[n] != 0) return dp[n];

	int ans = 0;
	for (int jump = 1; jump <= k; jump++) {
		ans += ways_topDown(n - jump, k, dp);
	}
	return dp[n] = ans;
}

int ways_bottomUp(int n, int k) {
	vector<int>dp(n + 1, 0);

	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {

		for (int jump = 1; i <= k; jump++) {

			if (i - jump >= 0)
				dp[i] += dp[i - jump];
		}

	}
	return dp[n];
}
int bottomUp_optimized(int n, int k) {
	vector<int>dp(n + 1, 0);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= k; i++) {
		dp[i] = 2 * dp[i - 1];
	}

	for (int i = k + 1; i <= n; ++i)
	{
		dp[i] = 2 * dp[i - 1] - dp[i - k - 1]
	}

	return dp[n];
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;

	int dp[1000] = {0};
	cout << ways_topDown(n, k, dp) << endl;

}
