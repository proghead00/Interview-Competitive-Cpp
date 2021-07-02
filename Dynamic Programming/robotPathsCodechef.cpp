#include <bits/stdc++.h>
using namespace std;

#define ll 						long long
#define pb 						push_back
#define fr(a,b) 				for(int i = a; i < b; i++)
#define rep(i,a,b) 				for(int i = a; i < b; i++)
#define fr2(i,a,b,u) 			for(int i = a; i < b; i+=u)

#define mod 					1000000007
#define all(x) 					(x).begin(), (x).end()
#define prDouble(x) 			cout << fixed << setprecision(10) << x
#define triplet 				pair<ll,pair<ll,ll>>
#define goog(tno) 				cout << "Case #" << tno <<": "
#define read(x) 				int x; cin >> x
#define endl                    "\n"

#define ff             		    first
#define ss              		second
#define mp              		make_pair
#define pii             		pair<int,int>
#define vi              		vector<int>
#define mii             		map<int,int>
#define pqb             		priority_queue<int>
#define pqs             		priority_queue<int,vi,greater<int> >
#define setbits(x)      		__builtin_popcountll(x)
#define zrobits(x)      		__builtin_ctzll(x)
#define inf             		1e18
#define ps(x,y)         		fixed<<setprecision(y)<<x
#define mk(arr,n,type)  		type *arr=new type[n];
#define w(x)            		int x; cin>>x; while(x--)
mt19937                 		rng(chrono::steady_clock::now().time_since_epoch().count());


int dp[1001][1001];

int noOfWays(int R, int C) {

	if (dp[0][0] == -1) return 0;

	// no of ways for first row
	fr(0, C) {
		if (dp[0][i] == -1) break;

		dp[0][i] = 1;
	}

	// for cols
	fr(0, C) {
		if (dp[i][0] == -1) break;
		dp[i][0] = 1;
	}

	// bottom up
	fr2(i, 1, R, 1) {
		fr2(j, 1, C, 1) {

			if (dp[i][j] == -1) continue;

			dp[i][j] = 0;

			if (dp[i][j - 1] != -1) {
				dp[i][j] = dp[i][j - 1] % mod;
			}

			if (dp[i - 1][j] != -1) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
			}

		}
	}
	// check for final cell, if it's blocked
	if (dp[R - 1][C - 1] == -1) return 0;

	return dp[R - 1][C - 1];

}

void solve() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//code:

	memset(dp, 0, sizeof dp);

	int m, n, p; // rows, cols, blocks
	cin >> m >> n >> p;

	fr(0, p) {
		read(x);
		read(y);

		// mark all blocked cells as -1
		dp[x - 1][y - 1] = -1;

	}

	cout << noOfWays(m, n) << endl;
}

int32_t main() {

	solve();
	return 0;
}