#include <iostream>
#include <algorithm>
using namespace std;

int maxSum(int arr[], int n) {
	// special case: if all the numbers are negative
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) c++;
	}
	if (c == n) return *max_element(arr, arr + n);

	else {
		int dp[100] = {0};
		dp[0] = arr[0] > 0 ? arr[0] : 0;
		int max_so_far = dp[0];

		for (int i = 1; i < n; ++i)
		{
			dp[i] = dp[i - 1] + arr[i];
			if (dp[i] < 0) dp[i] = 0;

			max_so_far = max(dp[i], max_so_far);
		}

		return max_so_far;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int arr[] = { -3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
	// int arr[] = { -1, 4, -5, -5, -5, -6, -7, -5, -111};
	int  n = sizeof(arr) / sizeof(int);

	cout << maxSum(arr, n);
}