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

const int N = 1e5, M = 400;
string input[M];
vi gr[N];
int vis[N][M];

map<pair<int, int>, int> codeMap;
int curCount;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int low[N], disc[N], vis_arti[N], tme = 1;
int artiCounter;

int n, m;

//---------------------------------------------------------------------------------------------------------

void ff(int x, int y) {

	vis[x][y] = 1;

	fr(0, 4) {

		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 and xx < n and yy >= 0 and yy < m and !vis[xx][yy] and input[xx][yy] == 'g') {
			ff(xx, yy);
		}

	}
}

//---------------------------------------------------------------------------------------------------------

void addEdges() {

	fr(0, n) {
		fr2(j, 0, m, 1) {

			if (input[i][j] == 'g') {

				int currentCode = codeMap[ {i, j}];

				if (i + 1 < n and input[i + 1][j] == 'g')
					gr[currentCode].pb(codeMap[ {i + 1, j}]);

				if (i and input[i - 1][j] == 'g')
					gr[currentCode].pb(codeMap[ {i - 1, j}]);

				if (j and input[i][j - 1] == 'g')
					gr[currentCode].pb(codeMap[ {i, j - 1}]);

				if (j + 1 < m and input[i][j + 1] == 'g')
					gr[currentCode].pb(codeMap[ {i, j + 1}]);
			}
		}
	}
}

//---------------------------------------------------------------------------------------------------------




void arti_DFS(int cur, int par) {
	vis_arti[cur] = 1;
	low[cur] = disc[cur] = tme++;

	int children = 0;

	for (auto x : gr[cur]) {

		if (!vis_arti[x]) {
			arti_DFS(x, cur);
			children++;

			low[cur] = min(low[cur], low[x]);

			if (par != -1 and low[x] >= disc[cur]) artiCounter++;

		}
		else if (x != par) {
			low[cur] = min(low[cur], disc[x]);
		}
	}

	if (par == -1 and children > 1) artiCounter++;
}



//---------------------------------------------------------------------------------------------------------

void solve() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code:

	cin >> n >> m;

	fr(0, n) {
		fr2(j, 0, m, 1) {
			cin >> input[i][j];
		}
	}

	// graph with only 'g's
	fr(0, n) {
		fr2(j, 0, m, 1) {
			if (input[i][j] == 'g')
				codeMap[ {i, j}] = curCount++;
		}
	}

	addEdges();

	//--------------------------------------------------------------------

	int conn = 0;
	fr(0, n) {
		fr2(j, 0, m, 1) {
			if (input[i][j] == 'g' and !vis[i][j]) {
				conn++;
				ff(i, j);
			}
		}
	}

	// for (auto x : codeMap) {
	// 	cout << x.ff.ff <<  "," << x.ff.ss << " -> ";
	// 	cout << x.ss;
	// 	cout << endl;
	// }

	// cout << endl;
	// cout << endl;

	// fr(0, m) {
	// 	cout << i << " -> ";
	// 	for (auto x : gr[i])
	// 		cout << x << " ";
	// 	cout << endl;
	// }


	// conn = 1 means that it has ONLY one whole component => not disconnected
	// cout << conn;

	if (conn > 1) cout << 0;
	else {
		arti_DFS(0, -1);
		if (artiCounter) cout << 1;
		else cout << 2;

	}
}

int32_t main() {
	solve();
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";

	return 0;
}