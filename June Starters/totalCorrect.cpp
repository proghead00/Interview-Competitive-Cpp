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


void solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//code:
	w(t) {
		unordered_map<string, int> m;
		read(n);
		fr(0, n * 3) {
			string s; int c;
			cin >> s >> c;
			if (m.find(s) == m.end())
				m.insert({s, c});
			else
				m[s] += c;
		}

		vector<int>v;
		for (auto x : m) v.pb(x.second);

		sort(v.begin(), v.end());
		fr(0, v.size()) cout << v[i] << " ";

		// int lm = m.size();
		// int arr[lm];

		// for (auto x : m) {
		// 	fr(0, m.size()) {
		// 		arr[i] = x.second;
		// 	}
		// }

		// sort(arr, arr + m.size());
		// fr(0, m.size()) cout << arr[i] << " ";
		cout << endl;
	}
}


int32_t main()
{
	solve();
	return 0;
}