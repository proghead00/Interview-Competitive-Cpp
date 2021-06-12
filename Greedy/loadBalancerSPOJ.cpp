#include <iostream>
using namespace std;


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int arr[90000];
	int n, i, val, diff = 0;

	while (true) {

		int maxLoad = 0, load = 0;
		cin >> n;

		// stop taking input when n=-1
		if (n == -1) {
			break;
		}

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			load += arr[i];

		}

		if (load % n != 0) {
			cout << -1 << endl;
			continue;
		}

		// else divide the load equally
		load /= n;

		for (int i = 0; i < n; i++) {
			// find diff b/w final load to be assigned and curr node
			diff += (arr[i] - load);
			int ans = abs(diff);
			maxLoad = max(maxLoad, ans);
		}

		cout << maxLoad << endl;
	}
}
