#include <iostream>
#include <unordered_set>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	unordered_set<int> s;

	int ans = 0;
	int j = 0;

	// fix starting point
	for (int i = 0; i < n; i++) {

		// find ending point of curr subarray w/ distinct elements
		while (j < n and s.find(a[j]) == s.end()) {

			s.insert(a[j]);
			j++;
		}

		ans +=  ((j - i) * (j - i + 1)) / 2;

		// remove a[i] since we need to move forward
		s.erase(a[i]);
	}

	cout << ans << endl;
}