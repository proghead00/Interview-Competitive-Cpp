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


const int N = 1e5;
vi gr[N];
int vis[N];
int col[N];
int one = 0, zero = 0;
bool flag = true;
const int modulo = 998244353;

// -------------------------------------------------------------------------------------------------------
int fastPow(int a, int b) {
	int res = 1;
	a = a % modulo;
	while (b) {
		if (b & 1)
			res = (res * a) % modulo;
		a = (a * a) % modulo;
		b >>= 1;
	}
	return res;
}

void dfs(int cur, int color) {
	if (color == 0)
		zero++;
	else
		one++;

	col[cur] = color;
	vis[cur] = 1;

	for (int child : gr[cur]) {

		if (!vis[child])
			dfs(child, 1 - color);

		else if (col[child] == col[cur]) {
			flag = false;
			return;
		}
	}

}

void solve() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code:

	w(t) {
		read(n);
		read(m);

		while (m--) {
			read(x); read(y);
			gr[x].pb(y);
			gr[y].pb(x);
		}


		int ans = 1;

		fr(1, n + 1) {
			if (!vis[i]) {
				zero = 0;
				one = 0;
				flag = true;

				dfs(i, 0);

				if (flag) {
					ans *= fastPow(2, one) + fastPow(2, zero);
					ans %= modulo;
				}
				else break;
			}

		}

		(flag) ? cout << ans << endl : cout << 0 << endl;

	}

}

int32_t main() {
	solve();
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";

	return 0;
}