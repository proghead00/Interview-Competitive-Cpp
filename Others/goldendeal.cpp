#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        long long x[n];

        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }

        unordered_map<int, int> hash;

        for (size_t i = 0; i < n; i++)
            hash[x[i]]++;

        int maxc = 0, ans = -1;
        for (auto i : hash)
        {
            if (maxc < i.second)
            {
                ans = i.first;
                maxc = i.second;
            }
        }

        if (ans > (n / 2))
            cout << ans << endl;

        else
            cout << "-1" << endl;
    }
    return 0;
}
