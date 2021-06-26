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

	read(t);
	while (t--) {
		string s;
		cin >> s;

		int len = s.length();
		int c = 0, f = 0;

		if (len < 4) {
			cout << "Error" << endl;
		}

		else {


			fr(0, len - 1) {
				if (s[i] >= 33 and s[i] <= 126) f = 0;
				else f = 1;
			}

			if (f == 1) cout << "Error";
			else {

				if (s[0] == '<' and s[1] == '/' and s[len - 1] == '>') {

					fr(2, len - 1) {
						if ((s[i] >= 48 and s[i] <= 57) or (s[i] >= 97 and s[i] <= 127))
							c++;
					}
					if (c == len - 3) {
						cout << "Success" << endl;
						// break;
					}
					else {
						cout << "Error" << endl;
						// break;
					}

				}

				else {
					cout << "Error" << endl;
					// break;
				}
			}

		}
	}
}

int32_t main()
{
	solve();
	return 0;
}