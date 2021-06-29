#include <bits/stdc++.h>
using namespace std;

#define ll                         long long
#define pb                         push_back
#define fr(a,b)                 for(int i = a; i < b; i++)
#define rep(i,a,b)                 for(int i = a; i < b; i++)
#define fr2(i,a,b,u)             for(int i = a; i < b; i+=u)

#define mod                     1000000007
#define all(x)                     (x).begin(), (x).end()
#define prDouble(x)             cout << fixed << setprecision(10) << x
#define triplet                 pair<ll,pair<ll,ll>>
#define goog(tno)                 cout << "Case #" << tno <<": "
#define read(x)                 int x; cin >> x
#define endl                    "\n"

#define ff                         first
#define ss                      second
#define mp                      make_pair
#define pii                     pair<int,int>
#define vi                      vector<int>
#define mii                     map<int,int>
#define pqb                     priority_queue<int>
#define pqs                     priority_queue<int,vi,greater<int> >
#define setbits(x)              __builtin_popcountll(x)
#define zrobits(x)              __builtin_ctzll(x)
#define inf                     1e18
#define ps(x,y)                 fixed<<setprecision(y)<<x
#define mk(arr,n,type)          type *arr=new type[n];
#define w(x)                    int x; cin>>x; while(x--)
mt19937                         rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[100][100];

int sum(int *arr, int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
    {
        s += arr[k];
        s = s % 100;
    }
    return s;
}


int minSmoke(int *arr, int i, int j)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        ans = min(ans, minSmoke(arr, i, k) + minSmoke(arr, k + 1, j) + sum(arr, i, k) * sum(arr, k + 1, j));
    }
    return dp[i][j] = ans;
}


void solve()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //code:
    int n;
    // cin>>n;

    int *arr = new int[n];
    while ((scanf("%d", &n)) != EOF) {

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << minSmoke(arr, 0, n - 1) << endl;
    }


}

int32_t main()
{
    solve();
    return 0;
}


