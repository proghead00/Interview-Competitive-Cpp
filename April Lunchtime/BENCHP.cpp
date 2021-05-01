#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, w, wr;

        cin >> n >> w >> wr;
        map<long, long> mp;

        int a[n];

        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }

        if (wr >= w)
        {
            cout << "YES" << endl;
        }
        else
        {
            w -= wr;

            for (size_t i = 0; i < n; i++)
            {
                if (mp[a[i]] >= 2)
                {
                    int cnt = mp[a[i]];

                    if (cnt % 2 == 0)
                    {
                        w -= cnt * a[i];
                    }

                    else
                    {
                        w -= (cnt - 1) * a[i];
                    }

                    mp[a[i]] = 0;
                }

                if (w <= 0)
                {
                    break;
                }
            }

            if (w <= 0)
                cout << "YES" << endl;

            else
                cout << "NO" << endl;
        }
    }
}
