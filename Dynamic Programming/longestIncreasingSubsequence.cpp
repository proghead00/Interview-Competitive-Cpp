#include <iostream>
#include <algorithm>
using namespace std;

//O(n^2)
int LIS1(int arr[], int n) {
	int lis[n];
	lis[0] = 1;

	for (int i = 1; i < n; i++) {
		lis[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				lis[i] = max(lis[i], lis[j] + 1);
		}
	}

	// either this --> cout << *max_element(lis, lis + n);
	// or:
	int res = lis[0];
	for (int i = 0; i < n; ++i) {
		res = max(res, lis[i]);
	}
	return res;
}

int ceilIdx(int tail[], int n, int x) {
	auto it = upper_bound(tail, tail + n, x);
	return (it - tail);
}

//O(nlogn)
int LIS2(int arr[], int n) {
	int tail[n], len = 1;
	tail[0] = arr[0];

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] > tail[len - 1]) {
			tail[len] = arr[i];
			len++;
		}
		else {
			int c = ceilIdx(tail,  len - 1, arr[i]);
			tail[c] = arr[i];
		}
	}
	return len;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {8, 100, 150, 10, 12, 14, 110};
	int n = sizeof(arr) / sizeof(int);

	cout << LIS2(arr, n);

}