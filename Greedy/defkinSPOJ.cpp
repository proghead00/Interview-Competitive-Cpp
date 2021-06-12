#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	while (t--) {
		int w, h, n;
		cin >> w >> h >> n;
		vector<int> a;
		vector<int> b;

		a.push_back(0);
		b.push_back(0);

		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			a.push_back(x);
			b.push_back(y);
		}

		// pushing the last point
		a.push_back(w + 1);
		b.push_back(h + 1);


		// we need to sort since the towers are inputted in random
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int mx = 0, my = 0;

		for (int i = 0; i < a.size() - 1; i++) {
			mx = max(mx, a[i + 1] - a[i] - 1);
			my = max(my, b[i + 1] - b[i] - 1);
		}

		cout << mx*my << endl;

	}
}