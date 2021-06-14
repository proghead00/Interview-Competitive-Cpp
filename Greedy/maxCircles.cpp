#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {

	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}

	return p1.second < p2.second;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<pair<int, int>> v;

	int c, r;
	for (int i = 0; i < n; i++) {
		cin >> c >> r;
		v.push_back({c - r, c + r});
	}
	sort(v.begin(), v.end(), cmp);

	int cnt = 0;
	int curr = v[0].second;
	for (int i = 1; i < n; i++) {
		if (curr <= v[i].first)  curr = v[i].second;
		else cnt++;
	}

	cout << cnt << endl;
	v.clear();
	return 0;
}