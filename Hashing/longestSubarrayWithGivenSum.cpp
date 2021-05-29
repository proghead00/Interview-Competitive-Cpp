#include <iostream>
#include <unordered_map>
using namespace std;

<<<<<<< HEAD:Hashing/longestSubarrayWithGivenSum.cpp
int longestSubarrayWithGivenSum(int arr[], int n, int k) {
=======
int longestSubarrayWithZeroSum(int arr[], int n) {
>>>>>>> 265cef4548c3962a772e386471e47116373326b1:Hashing/longestSubarrayWithZeroSum.cpp
	unordered_map<int, int> m;
	int pre = 0, len = 0;

	for (int i = 0; i < n; i++) {
		pre += arr[i];

		if (pre == k)
		{
			len = max(len, i + 1);
		}


		if (m.find(pre - k) != m.end()) // if that element is already present
		{
			len = max(len, i - m[pre - k]);
		}

		else // first occurence of the element
		{
			m[pre] = i;
		}
	}

	return len;

}

int main() {
	int n;
	cin >> n;
	int k;
	cin >> k;
	int arr[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << longestSubarrayWithGivenSum(arr, n, k) << " ";


}
