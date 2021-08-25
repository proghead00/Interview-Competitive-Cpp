#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define eb                  emplace_back
#define pb                  push_back
#define fr(a,b)             for(int i = a; i < b; i++)
#define fr2(a,b)            for(int j = a; j < b; j++)
#define fr3(a,b)            for(int k = a; k < b; k++)

#define rep(i,a,b)          for(int i = a; i < b; i++)
#define fr4(i,a,b,u)        for(int i = a; i < b; i+=u)
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
int n, m;
const int N = 1e5 + 5;
vector<pii> gr[N];

vi dist(N, LLONG_MAX);
int vis[N];
int par[N];
int pathExists = 0;
stack<int> path;

void generatePath(int dest) {
	path.push(dest);
	int node = dest;

	while (par[node]) {
		node = par[node];
		path.push(node);
	}

}

void dijkstra(int src, int dest) {
	fr(0, n) {
		dist[i] = LLONG_MAX;
		vis[i] = 0;
	}

	dist[src] = 0;
	priority_queue <pii> pq; // {dist, node}

	pq.push({0, src});

	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();

		// smol optimization
		if (vis[cur.ss]) continue;
		vis[cur.ss] = 1;

		// cur => pii (dist, node)
		for (auto x : gr[cur.ss]) {
			int nbr = x.ss;
			int wt = x.ff;

			if (dist[nbr] > dist[cur.ss] + wt) {
				// update distance first and then push it to the pq
				dist[nbr] = dist[cur.ss] + wt;
				pq.push({ -dist[nbr], nbr });
				par[nbr] = cur.ss;
			}
		}
	}

	if (dist[dest] != LLONG_MAX) {
		pathExists = 1;
		generatePath(dest);
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
		read(a); read(b); read(w);
		gr[a].pb({w, b});
		gr[b].pb({w, a});
	}

	dijkstra(1, n);

	if (!pathExists) cout << -1;
	else {
		while (!path.empty()) {
			cout << path.top() << " ";
			path.pop();
		}
	}
}

int32_t main() {
	solve();
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";

	return 0;
}