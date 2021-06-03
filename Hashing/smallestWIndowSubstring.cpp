#include <iostream>
#include <climits>
#include <string>
using namespace std;

string window(string s, string pat) {
	int stringLen = s.length();
	int patternLen = pat.length();

	if (patternLen > stringLen) return "None";

	int stringFreq[256] = {0};
	int patFreq[256] = {0};

	// count freq of pattern
	for (int i = 0; i < patternLen; i++) {
		char ch = pat[i];
		patFreq[ch]++;
	}

	// sliding window -> expansion, contraction, update min length of window
	// i -> to expand; start-> to shrink

	int start = 0, cnt = 0, minLength  = INT_MAX;

	int startIdx = -1;

	for (int i = 0; i < stringLen; i++) {
		char ch = s[i];
		stringFreq[ch]++;

		// maintain the count of characters matched
		if (patFreq[ch] != 0 and stringFreq[ch] <= patFreq[ch]) {
			cnt++;
		}

		// if all char match
		if (cnt == patternLen) {
			char temp = s[start];

			// if the char is not needed
			while (patFreq[temp] == 0 or stringFreq[temp] > patFreq[temp]) {
				stringFreq[temp]--;
				start++;
				temp = s[start];
			}

			// ending point is i; starting point is start
			int windowLength = i - start + 1;

			if (windowLength < minLength) {
				minLength = windowLength;
				startIdx = start;
			}

		}
	}

	if (startIdx == -1) return "None";

	string ans = s.substr(startIdx, minLength);
	return ans;
}


int main() {
	string s = "qwerty asdfgh qazxsw";
	string p = "qas";

	cout << window(s, p);

}
