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

//---------------------------------------------------------------------------------------------------
// GLOBAL VARIABLES:

const int N = 1e5, M = 22;
vi gr[N];

int tin[N], tout[N], timer;


//---------------------------------------------------------------------------------------------------
void eulerTour__1(int curr, int par) {

// enter a node -> print
// exit a node -> print

    cout << curr << " ";

    for (auto x : gr[curr]) {
        if (x != par) {
            eulerTour__1(x, curr);
            cout << curr << " ";
        }
    }
    return;
}

void eulerTour__2(int curr, int par) {

// enter a node -> print
// coming back from a node -> print

    cout << curr << " ";

    // tin[curr] = timer++;

    for (auto x : gr[curr]) {
        if (x != par) {
            eulerTour__2(x, curr);
        }
    }

    // toutcurr] = timer++;

    cout << curr << " ";
    return;
}


void eulerTour__3(int curr, int par) {

// ONLY PRINT WHEN entering a node
// exit => time won't be increased

    tin[curr] = ++timer; // First INCREMENT and then store
    cout << curr << " ";

    for (auto x : gr[curr]) {
        if (x != par) {
            eulerTour__3(x, curr);
        }
    }
    tout[curr] = timer;
    return;
}


bool isAncestor(int x, int y) {
    // whether x is ancestor of y
    return tin[x] <= tin[y] and tout[x] >= tout[y];
}

void solve() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // code:

    read(n);

    fr(0, n - 1) {
        read(x); read(y);
        gr[x].pb(y);
        gr[y].pb(x);
    }

    timer = 0;
    // eulerTour__1(1, 0);
    // eulerTour__2(1, 0);
    eulerTour__3(1, 0);

    cout << endl;

    fr(1, n + 1) {
        cout << i << " --> " << tin[i] << " " << tout[i] << endl;
    }
    cout << endl;

    if (isAncestor(6 , 7)) cout << "YES";
    else cout << "NO";

}

int32_t main() {
    solve();
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";

    return 0;
}