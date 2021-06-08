#include <iostream>
#include <climits>
#include <string>
using namespace std;

string window(string s1, string s2) {

	// corner case
	if (s2.length() > s1.length())
		return "No String";

	// freq arrays
	int fs1[256] = {0};
	int fs2[256] = {0};

	for (int i = 0; i < s2.length(); i++)
	{
		char ch = s2[i];
		fs2[ch]++;
	}

	int start = 0, cnt = 0, start_idx = -1, min_len = INT_MAX;

	for (int i = 0; i < s1.length(); i++)
	{
		char ch = s1[i];
		fs1[ch]++;

		// no. of characters matched
		if (fs2[ch] != 0 and fs1[ch] <= fs2[ch])
			cnt++;


		// if all characters match
		if (cnt ==  s2.length()) {
			char temp = s1[start];

			// remove unwanted characters
			while (fs2[temp] == 0 or fs1[temp] > fs2[temp]) {
				fs1[temp]--;
				start++;
				temp = s1[start];
			}

			int window_len = i - start + 1;
			if (window_len < min_len)
			{
				min_len = window_len;
				start_idx = start;
			}
		}
	}

	if (start_idx == -1)
		return "No String";

	string ans = s1.substr(start_idx, min_len);
	return ans;

}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	cout << window(s1, s2);


}
