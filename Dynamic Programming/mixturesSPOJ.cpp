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

ll arr[1000];
ll dp[1000][1000];


ll csum(int s, int e) {
	ll ans = 0;

	fr(s, e + 1) {
		ans += arr[i];
		ans %= 100;
	}
	return ans;
}

ll mx(int i, int j) {
	if (i >= j) return 0;

	if (dp[i][j] != -1) return dp[i][j];

	dp[i][j] = INT_MAX;

	fr2(k, i, j + 1, 1) {
		dp[i][j] = min(dp[i][j], mx(i, k) + mx(k + 1, j) + csum(i, k) * csum(k + 1, j));
	}

	return dp[i][j];

}

void solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//code:

	int n;

	// no of test cases is not given, therefore read till end of line
	while ((scanf("%d", &n)) != EOF) {
		fr(0, n) cin >> arr[i];

		fr2(i, 0, n + 1, 1) {
			fr2(j, 0, n + 1, 1) {
				dp[i][j] = -1;
			}
		}
		cout << mx(0, n - 1) << endl;
	}
}

int32_t main()
{
	solve();
	return 0;
}