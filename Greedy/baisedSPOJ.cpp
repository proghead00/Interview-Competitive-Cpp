#include <iostream>
#include <cstring>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int arr[100000] = {0}; // freq array
	int t;
	cin >> t;

	while (t--) {
		memset(arr, 0, sizeof (arr));
		string name;
		int n, rank;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> name >> rank;
			arr[rank]++; // preferred rank
		}

		// greedy: assign the team to the nearest rank available

		int actualRank = 1;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			while (arr[i]) // not empty
			{
				sum += abs(actualRank - i);
				arr[i]--;
				actualRank++;
			}

		}
		cout << sum << endl;
	}
}