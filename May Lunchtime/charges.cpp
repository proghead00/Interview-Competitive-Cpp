#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {


		int n, k;
		cin >> n >> k;

		string s;
		cin >> s; // charge

		int q[k]; // priorities

		for (int i = 0; i < k; i++) {
			cin >> q[i];
		}
		for (int i = 0; i < k; i++) {
			q[i] -= 1; // indexing from 0
		}

		int sum = 0;

		for (int i = 0; i < k; i++) {
			int pos = q[i];
			if (s[i] == '1') s[i] = '0';
			else if (s[i] == '0') s[i] == '1';

			for (int j = 0; j < n - 1; j++) {
				if (s[i] == '0') {
					if (s[i + 1] == '0')
						sum += 2;
					else
						sum += 1;
				}
				else {
					if (s[i + 1] == '1')
						sum += 1;
					else
						sum += 2;
				}

			}
			cout << sum << endl;

		}

	}
}