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

const int N = 1e5, M = 20; // M = log N
vi gr[N];
int depth[N], Par[N][M];

// IN SPARSE TABLE Par:
// first col: 2^0 = 1st parent; second col: 2^2 = 4th parent...


// -------------------------------------------------------------------------------------------------------


// O(N*M)
void dfs(int cur, int par) {
	depth[cur] = depth[par] + 1;

	Par[cur][0] = par; // 2^0 = 1st parent (in the 1st col)

	fr2(j, 1, M, 1) {
		Par[cur][j] = Par[Par[cur][j - 1]][j - 1];
	}

	for (auto x : gr[cur]) {
		if (x != par) {
			dfs(x, cur);
		}
	}
}


// O(M) = logN
int lca__binaryLifting(int u, int v) {
	if (u == v) return u;

	if (depth[u] < depth[v]) swap(u, v);

	int diff = depth[u] - depth[v];

	for (int j = M - 1; j >= 0; j--) {
		if ((diff >> j) & 1) {
			// jth bit of diff is set
			// 10 => 1010 => 2^3 + 2^1 = 10

			u = Par[u][j];
		}
	}

	// u and v are on the same level now
	for (int j = M - 1; j >= 0; j--) {
		if (Par[u][j] != Par[v][j]) {
			u = Par[u][j];
			v = Par[v][j];
		}
	}

	return Par[u][0];
}

// O(1)
int lengthFromUtoV(int u, int v) {
	int lca = lca__binaryLifting(u, v);
	return depth[u] + depth[v] - 2 * depth[lca];
}



void solve() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code:

	read(n);

	// tree -> n-1 edges
	fr(1, n) {
		read(x); read(y);
		gr[x].pb(y);
		gr[y].pb(x);
	}

	dfs(1, 0);
	fr2(i, 1, 13, 1) {
		cout << i << " -> ";
		fr2(j, 0, 4, 1) {
			cout << Par[i][j] <<  " ";
		}

		cout << endl;
	}

	// cout << lca__binaryLifting(10, 8);
	// cout << lengthFromUtoV(9, 12);

}

int32_t main() {
	solve();
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";

	return 0;
}