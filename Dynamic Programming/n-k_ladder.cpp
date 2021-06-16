#include <iostream>
using namespace std;

int ways(int n, int k, int *dp) {
	if (n == 0) return 1;

	if (n < 0) return 0;

	if (dp[n] != 0) return dp[n];

	int ans = 0;
	for (int jump = 1; jump <= k; jump++) {
		ans += ways(n - jump, k, dp);
	}
	return dp[n] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;

	int dp[1000] = {0};
	cout << ways(n, k, dp) << endl;

}