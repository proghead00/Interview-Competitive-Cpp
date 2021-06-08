#include <iostream>
#include <map>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int l;
		cin >> l;

		map<int, bool> hm;
		int num;

		for (int j = 0; j < l; j++) {
			cin >> num;
			hm[num] = 1;
		}

		int q;
		cin >> q;
		int query;

		for (int k = 0; k < q; k++) {
			cin >> query;
			if (hm.count(query) > 0) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}