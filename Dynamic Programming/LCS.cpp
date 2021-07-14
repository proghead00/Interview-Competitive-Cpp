#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;


#define ll                  long long
#define pb                  push_back
#define fr(a,b)             for(int i = a; i < b; i++)
#define rep(i,a,b)          for(int i = a; i < b; i++)
#define fr2(i,a,b,u)        for(int i = a; i < b; i+=u)
#define endl                "\n"
#define vp                  vector<pair<int,int>

#define inf                 (1LL<<60)
#define all(x)              (x).begin(), (x).end()
#define prDouble(x)         cout << fixed << setprecision(10) << x
#define triplet             pair<ll,pair<ll,ll>>
#define goog(tno)           cout << "Case #" << tno <<": "
#define read(x)             int x; cin >> x

#define ff                  first
#define ss                  second
#define int                 long long
#define pb                  push_back
#define mp                  make_pair
#define pii                 pair<int,int>
#define vi                  vector<int>
#define mii                 map<int,int>
#define pqb                 priority_queue<int>
#define pqs                 priority_queue<int,vi,greater<int> >
#define setbits(x)          __builtin_popcountll(x)
#define zrobits(x)          __builtin_ctzll(x)
#define mod                 1000000007
// #define inf              1e18
#define ps(x,y)             fixed<<setprecision(y)<<x
#define mk(arr,n,type)      type *arr=new type[n];
#define w(x)                int x; cin>>x; while(x--)
mt19937                     rng(chrono::steady_clock::now().time_since_epoch().count());

int memo[10001][10001];

// O(m*n)
int lcs_topDown(string s1, string s2, int m, int n) {

	if (memo[m][n] != -1) return memo[m][n];

	if (m == 0 or n == 0) memo[m][n] = 0;

	else {
		if (s1[m - 1] == s2[n - 1])
			memo[m][n] = 1 + lcs_topDown(s1, s2, m - 1, n - 1);
		else
			memo[m][n] = max(lcs_topDown(s1, s2, m - 1, n), lcs_topDown(s1, s2, m, n - 1));
	}
	return memo[m][n];

}

int lcs_bottomUp(string s1, string s2, int m, int n) {
	int dp[m + 1][n + 1];

	fr(0, m + 1) dp[i][0] = 0;

	fr2(j, 0, n + 1, 1) dp[0][j] = 0;

	fr(1, m + 1) {
		fr2(j, 1, n + 1, 1) {
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[m][n];
}

void solve() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code:
	string s1, s2;

	getline(cin, s1);
	getline(cin, s2);

	cout << lcs_topDown(s1, s2, s1.length(), s2.length()) << endl;
	cout << lcs_bottomUp(s1, s2, s1.length(), s2.length());

}

int32_t main() {

	memset(memo, -1, sizeof (memo));

	solve();
	return 0;
}