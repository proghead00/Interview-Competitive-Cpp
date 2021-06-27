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

int sqr2(int num)
{
	int odd = 1;
	int sq = 0;

	num = abs(num);

	while (num--)
	{
		sq = sq + odd;
		odd = odd + 2;
	}

	return sq;
}

void solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//code:
	ll n, q;
	cin >> n >> q;

	// read(n);
	// read(q);

	// vi v(n);

	vector<long long>v(n);
	fr(0, n) cin >> v[i];

	while (q--) {
		long long num;
		cin >> num;
		// read(num);

		if (num == 1) {
			long long l, r, x;
			cin >> l >> r >> x;
			// read(l);
			// read(r);
			// read(x);

			// fr(l - 1, r) v[i] += sqr2(x + i + 1 - l);
			fr(l - 1, r) v[i] = v[i] +  (x + i + 1 - l) * (x + i + 1 - l);
		}
		if (num == 2) {
			long long y;
			cin >> y;
			// read(y);
			cout << v[y - 1] << endl;

		}

	}

}

int32_t main()
{
	solve();
	return 0;
}