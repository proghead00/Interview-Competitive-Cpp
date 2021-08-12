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

// --------------------------------------------------------------------------------------------------------------------
// GLOBAL VARIABLES:

const int N = 1e5;

vi gr[N], grr[N];  // graph and reversed graph

int vis[N];
vi order;

int color[N]; // color represents the component to which that node belongs to

vi components[N];

// --------------------------------------------------------------------------------------------------------------------
// O(n+m)

// sink nodes: no outgoing edges

void dfs__1(int cur) {
	vis[cur] = 1;

	for (auto x : gr[cur]) {
		if (!vis[x]) dfs__1(x);
	}
	order.pb(cur);
}

void dfs__2(int cur, int comp) {
	vis[cur] = 1;
	color[cur] = comp;

	components[comp].pb(cur);

	for (auto x : grr[cur]) {
		if (!vis[x]) dfs__2(x, comp);
	}
}

void solve() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code:

	read(n);

	w(m) {
		read(x); read(y);
		gr[x].pb(y);
		grr[y].pb(x);
	}

	fr(1, n + 1) {
		if (!vis[i]) dfs__1(i);
	}
	reverse(order.begin(), order.end());

	memset(vis, 0, sizeof vis);

	int comp = 1;
	for (auto x : order) {
		if (!vis[x]) dfs__2(x, comp++);
	}

	fr(1, n + 1) {
		cout << i << " --> " << color[i] << endl;
	}

	cout << "Total no. of Strongly Connected Components: " << --comp << endl;

}

int32_t main() {
	solve();
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";

	return 0;
}