#include <iostream>
#include <climits>
using namespace std;

int change_topDown(int n, int coins[], int T, int dp[]) {

	if (n == 0) return 0;

	int ans = INT_MAX;

	if (dp[n] != 0) return dp[n];

	for (int i = 0; i < T; i++) {
		if (n - coins[i] >= 0) {
			int subprob = change_topDown(n - coins[i], coins, T, dp);
			ans = min(ans, subprob + 1);
		}
	}

	return dp[n] = ans;
}

int change_bottomUp(int N, int coins[], int T) {
	int dp[100] = {0};

	// iterate over all states 1...N
	for (int n = 1; n <= N; n++) {
		dp[n] = INT_MAX;

		for (int t = 0; t < T; t++) {
			if (n - coins[t] >= 0) {
				int subproblem = dp[n - coins[t]];
				dp[n] = min(dp[n], subproblem + 1);
			}
		}
	}
	return dp[N];
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int N = 15;
	int coins[] = {1, 7, 10};
	int dp[100] = {0};
	int T = 3;

	cout << change_topDown(N, coins, T, dp) << endl;
	cout << change_bottomUp(N, coins, T) << endl;
}