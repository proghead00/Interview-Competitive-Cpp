#include <iostream>
#include <unordered_map>
using namespace std;

// O(N)
int largestSequence(int arr[], int n) {
	unordered_map<int, int> m; // value mapping to streak length

	for (int i = 0; i < n; i++) {
		int num = arr[i];

		// new streak formation
		if (m.count(num - 1) == 0 and m.count(num + 1) == 0) {
			m[num] = 1;
		}

		else if (m.count(num - 1) and m.count(num + 1)) {
			int leftLen = m[num - 1];
			int rightLen = m[num + 1];

			int streak = leftLen + 1 + rightLen;
			m[num - leftLen] = streak;
			m[num - rightLen] = streak;
		}

		else if (m.count(num - 1) and !m.count(num + 1)) {
			int len = m[num - 1];
			m[num - len] = len + 1;
			m[num] = len + 1;
		}
		else if (!m.count(num - 1) and m.count(num + 1)) {
			int len = m[num + 1];
			m[num + len] = len + 1;
			m[num] = len + 1;
		}
	}

	int largest = 0;
	for (auto p : m) {
		largest = max(largest, p.second);
	}

	return largest;
}

int main() {
	int arr[] = {10, 4, 20, 1, 2, 8, 9, 3, 19};
	int n = sizeof(arr) / sizeof(int);

	cout << largestSequence(arr, n);
}