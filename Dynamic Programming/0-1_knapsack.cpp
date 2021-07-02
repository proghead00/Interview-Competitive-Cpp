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

int dp[1000][1000];

int topDown(int W, int wt[], int price[], int n) {

	if (n == 0 or W == 0) return 0;
	if (dp[n][W] != -1) return dp[n][W];

	int include = 0, exclude = 0;

	// if there's not enough space for a new wt to include in sack
	if (wt[n - 1] > W) return dp[n][W] = topDown(W, wt, price, n - 1);

	else {
		include = price[n - 1] + topDown(W - wt[n - 1], wt, price, n - 1);

		exclude = topDown(W, wt, price, n - 1);

		return dp[n][W] = max(include, exclude);
	}
}

int bottomUp(int W, int wt[], int price[], int N) {
	int dp2[N + 1][W + 1];

	fr2(i, 0, N + 1, 1) fr2(j, 0, W + 1, 1) dp2[i][j] = 0;

	int inc = 0, exc = 0;
	fr2(n, 1, N + 1, 1) {
		fr2(w, 1, W + 1, 1) {

			if (wt[n - 1] <= w)
				inc = price[n - 1] + dp2[n - 1][w - wt[n - 1]];

			exc = dp2[n - 1][w];

			dp2[n][w] = max(inc, exc);

		}
	}
	return dp2[N][W];
}

void solve() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//code:
	read(n);

	int wt[n]; int price[n];

	fr(0, n) {
		cin >> wt[i];
	}
	fr(0, n) {
		cin >> price[i];
	}

	read(W);

	// fr2(i, 0, n + 1, 1) {
	// 	fr2(j, 0, W + 1, 1)
	// 	dp[i][j] = -1;
	// }
	memset(dp, -1, sizeof dp);

	// cout << topDown(W, wt, price, n);
	cout << bottomUp(W, wt, price, n);
}

int32_t main() {

	solve();
	return 0;
}