#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// can select activity if the starting time of the new activity >= finishing time of the previous

bool compare(pair<int, int>p1, pair<int, int>p2) {
	return p1.second < p2.second;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t, n, s, e;
	cin >> t;
	vector<pair<int, int>> v; // first-> start; second-> ending time
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s >> e;
			v.push_back({s, e});
		}

		// activity selection
		sort(v.begin(), v.end(), compare);

		// start picking activities
		int res = 1; // first activity is picked already at first
		int finish = v[0].second;

		for (int i = 1; i < n; i++) {
			if (v[i].first >= finish) { //if the starting time (first) of the new activity >= finish
				finish = v[i].second;
				res++;
			}
		}

		cout << res << endl;
		v.clear();
	}
}