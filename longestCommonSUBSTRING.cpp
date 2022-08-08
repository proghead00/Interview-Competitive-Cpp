class Solution {
public:
  int help(string &s1, string &s2, int n, int m, vector<vector<int>> &dp) {

    if (dp[n][m] != -1) return dp[n][m];

    if (n == 0 or m = 0) return dp[n][m] = 0;

    if (s1[n - 1] == s2[m - 1]) dp[n][m] = 1 + help(s1, s2, n - 1, m - 1, dp);

    else dp[n][m] = 0;

    help(s1, s2, n - 1, m, dp);
    help(s1, s2, n, m - 1, dp);

    return dp[n][m];
  }

  int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    help(s1, s2, n, m, dp);

    int mx = 0;
    for (auto i : dp)
      for (auto j : i)
        mx = max(mx, j);

    return mx;

  }
};
