#include <iostream>
using namespace std;

int fib_topDown(int n, int dp[]) {

	if (dp[n] == -1) {
		int res;

		if (n == 0 or n == 1)
			res = n;
		else
			res = fib_topDown(n - 1, dp) + fib_topDown(n - 2, dp);

		dp[n] = res;
	}
	return dp[n];
}

// bottom up
int fib_spaceOptimized(int n) {

	if (n = 0 or n = 1) return n;
	int a = 0, b = 1, c;

	for (int i = 2; i < n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int fib_bottomUp(int n) {
	int dp[100] = {0};
	dp[1] = 1;
	for (int i = 0; i < n; i++) {
		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
	}
	return dp[n];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int dp[100];
	for (int i = 0; i < 100; i++) dp[i] = -1;

	cout << fib_topDown(n, dp) << endl;
	cout << fib_bottomUp(n) << endl;


}