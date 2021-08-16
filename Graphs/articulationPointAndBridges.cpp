#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define ll                  long long
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

const int N = 1e5;
vi gr[N];
int disc[N], low[N], tme;
set<int> arti_pt;
vp bridge; // pair --> (cur->child) forming a bridge


void dfs(int cur, int par) {

	disc[cur] = low[cur] = tme;
	tme++;

	int numOfChildren = 0;

	for (auto x : gr[cur]) {

		// NO NEED TO MAKE A VISITED ARRAY
		// IF disc HAS 0, IT AIN'T DISCOVERED
		if (!disc[x]) {
			dfs(x, cur);

			numOfChildren++;

			low[cur] = min(low[cur], low[x]);

			// art pt: for non root nodes
			if (par != 0 and low[x] >= disc[cur]) {
				arti_pt.insert(cur);
			}

			// bridge
			if (low[x] > disc[cur])
				bridge.pb({cur, x});
		}

		else if (x != par) {
			low[cur] = min(low[cur], disc[x]);
		}
	}

	// case for root to be an arti point
	if (par == 0 and numOfChildren > 1)	arti_pt.insert(cur);

	return;
}

void solve() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code:

	read(n);
	read(m);

	fr(0, m) {
		read(x); read(y);
		gr[x].pb(y);
		gr[y].pb(x);
	}
	tme = 1;
	dfs(1, 0);

	for (auto x : arti_pt) cout << x << " " ;


}

int32_t main() {
	solve();
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";

	return 0;
}