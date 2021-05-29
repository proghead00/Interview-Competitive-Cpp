#include <iostream>
#include <unordered_set>
using namespace std;
// O(N)
int longestConsecutive(int a[], int n) {
	unordered_set<int> s;

	for (int i = 0; i < n; i++) {
		s.insert(a[i]); //O(1)
	}
	int maxStreak = 1;
	for (int i = 0; i < n; i++) {
		if (s.find(a[i - 1]) == s.end()) {

			// a[i] is the starting head of the streak
			// traverse the entire range of the streak
			int nextNum = a[i] + 1;
			int streakLen = 1;
			while (s.find(nextNum) != s.end()) {
				nextNum++;
				streakLen++;
			}

			maxStreak max(streakLen, maxStreak);
		}
	}

	return max;
}

int main() {
	int arr[] = {10, 4, 20, 1, 2, 8, 9, 3, 19};
	int n = sizeof(arr) / sizeof(int);

	cout << longestConsecutive(arr, n);
}