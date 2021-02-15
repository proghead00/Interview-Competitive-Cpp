#include <bits/stdc++.h>
using namespace std;

bool isAns(long long n, long long k, long long ans)
{
    if (pow(ans, k) <= n)
    {
        return true;
    }

    return false;
}
int main()
{
    long long t, n, k;

    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        long long s = 1;
        long long e = n;
        long long ans;
        while (s <= e)
        {
            long long mid = (s + e) / 2;

            if (isAns(n, k, mid))
            {
                ans = mid;
                s = mid + 1;
            }

            else
                e = mid - 1;
        }

        cout << ans << endl;
    }
}