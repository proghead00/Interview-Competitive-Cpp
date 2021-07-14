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
#define vp                  vector<pair<int,int>>

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

int td[10001][10001];
bool palCheck(const string &s, int i, int j) {
	while (i < j) {
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}


int palPartTopDown(const string &s, int i, int j) {

	if (td[i][j] != -1) return td[i][j];

	if (palCheck(s, i, j) or i >= j) return 0;


	int ans = INT_MAX;

	fr2(k, i, j, 1) {
		int temp = 1 + palPartTopDown(s, i, k) + palPartTopDown(s, k + 1, j);
		ans = min(ans, temp);
	}
	return td[i][j] = ans;
}


// O(n^3)
int palPartBottomUp(const string &s) {
	int n = s.length();
	int dp[n][n];

	// single length strings are palindromes
	fr(0, n) dp[i][i] = 0;

	for (int gap = 1; gap < n; gap++) {
		for (int i = 0; i + gap < n; i++) {
			int j = i + gap;

			if (palCheck(s, i, j)) dp[i][j] = 0;
			else {

				dp[i][j] = INT_MAX;

				fr2(k, i, j, 1) {
					dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k + 1][j]);
				}
			}
		}
	}
	return dp[0][n - 1];
}

void solve() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code:

	string s;
	cin >> s;

	cout << palPartTopDown(s, 0, s.length() - 1);
	cout << endl;
	cout << palPartBottomUp(s);

}

int32_t main() {
	memset(td, -1, sizeof(td));

	solve();
	return 0;
}