#include <iostream>
#include <math.h>
#define ll long long
#define mod pow(10, 9) + 7
using namespace std;

ll fastExpo(ll x, ll n, ll m)
{
    ll res = 1;

    while (n > 0)
    {
        if (n & 1)
            res = (res * x) % m;

        x = (x * x) % m;
        n = n >> 1;
    }
    return res;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll ans = fastExpo(2, n - 1, mod);
        cout << ans << endl;
    }
}
