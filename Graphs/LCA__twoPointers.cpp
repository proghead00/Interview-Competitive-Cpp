#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define eb                  emplace_back
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
#define read(x)             long long x; cin >> x

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


// -------------------------------------------------------------------------------------------------------

const int N = 1e5;
vi gr[N];
int depth[N], Par[N];

// -------------------------------------------------------------------------------------------------------

void dfs__1(int cur, int par) {

	Par[cur] = par;
	depth[cur] = depth[par] + 1; // since initially it'd be set to 0 (since it's declared globally)


	for (auto x : gr[cur]) {
		if (x != par) dfs__1(x, cur);
	}
}


int lca__twoPointers(int u, int v) {
	if (u == v) return u;

	if (depth[u] < depth[v]) swap(u, v);
	// now, depth of u is always more than that of v => to create a consistency algorithm

	int diff  = depth[u] - depth[v];

	while (diff--) {
		u = Par[u];
	}

	// keep on climbing above until they're equal
	// they'll be equal at the LCA
	while (u != v) {
		u = Par[u];
		v = Par[v];
	}

	return u;
}

void solve() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code:

	read(n);
	int m = n - 1;

	while (m--) {
		read(x); read(y);
		gr[x].pb(y);
		gr[y].pb(x);
	}


	// using 2 ptrs:

	// dfs__1(1, 0);
	// cout << lca__twoPointers(4, 5);



	// --------------------------------------------------------------------------------------------------

	// with sparse table:

	dfs__2(1, 0);

	// fr2(i, 1, 13, 1) {
	// 	cout << i << " -> ";
	// 	fr2(j, 0, 4, 1) {
	// 		cout << sparseTable[i][j] <<  " ";
	// 	}

	// 	cout << endl;
	// }

	// cout << lca__binaryLifting(10, 8);
	cout << lengthFromUtoV(9, 12);


}

int32_t main() {
	solve();
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";

	return 0;
}