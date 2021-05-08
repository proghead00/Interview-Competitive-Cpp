#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        long long int n, x, k;
        int f = 0;
        int cnt = 0;

        cin >> n >> x >> k;

        (((x % k) == 0) || ((n + 1 - x) % k == 0)) ? cout << "YES"
                                                          << "\n"
                                                   : cout << "NO"
                                                          << "\n";
    }
}
