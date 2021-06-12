#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, t, x, d, f, L, P, prev = 0, ans = 0;


	cin >> t;
	while (t--) {
		int flag = 0;
		vector<pair<int, int>>v; // dist of fuel stations from town, capacities at each station wrt town
		priority_queue<int> pq; // largest fuel stations

		cin >> n; // no. of stops

		for (int i = 0; i < n; i++) {
			cin >> d >> f;
			v.push_back(make_pair(d, f));
		}


		std::sort(v.begin(), v.end(), greater<>());

		cin >> L >> P; // initial dist from stations; initial fuel in track


		// update the distance of fuel station from the truck
		for (int i = 0; i < n; i++) {
			v[i].first = L - v[i].first;
		}

		// prev denotes the prev city visited
		prev = 0;
		x = 0; // curr pos
		while (x < n) {
			// if there's enough fuel to go to next pos
			if (P >= (v[x].first - prev))
			{
				P -= (v[x].first - prev);
				pq.push(v[x].second);
				prev = v[x].first;
			}
			else // if we can't reach the next pos
			{
				//check if there are fuelling stations visited in pq

				// no fuelling stations:
				if (pq.empty()) {
					flag = 1;
					break;
				}

				// else refuel truck with higher capacity
				P += pq.top();

				// remove fuel station from pq
				pq.pop();
				ans++;
				continue;
			}

			// able to visit next pos
			x++;
		}
		// actually travalled thru n fuel stations, and now you need to just go to town from last fuel station
		if (flag == 1) cout << -1 << endl;

		L -= v[n - 1].first;
		if (P >= L) {
			cout << ans << endl;
			continue;
		}

		while (P < L) {
			if (pq.empty()) {
				flag = 1;
				break;
			}
			L += pq.top();
			pq.pop();
			ans++;
		}

		if (flag == 1) {
			cout << -1 << endl;
			continue;
		}
		cout << ans << endl;

	}
}