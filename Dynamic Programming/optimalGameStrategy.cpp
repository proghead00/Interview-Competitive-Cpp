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

int arr[1000];
int dp[1000][1000];

optimal(int i, int j) {
	if (i > j) return 0;

	if (dp[i][j] != -1) return dp[i][j];

	int x = arr[i] + min(optimal(i + 2, j), optimal(i + 1, j - 1));
	int y = arr[j] + min(optimal(i, j - 2), optimal(i + 1, j - 1));

	return dp[i][j] = max(x, y);
}

void solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//code:
	read(n);
	fr(0, n) cin >> arr[i];

	memset(dp, -1, sizeof dp);

	cout << optimal(0, n - 1);

}

int32_t main()
{
	solve();
	return 0;
}