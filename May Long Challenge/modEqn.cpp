#include <bits/stdc++.h>
using namespace std;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;

    cin >> t;

    while (t--)
    {
        long long int n, m;
        cin >> n >> m;

        long long int cnt = 0;
        vector<long long int> md(n + 1, 1);

        for (size_t i = 2; i <= n; i++)
        {
            long long int a = m % i;
            cnt += md[a];

            for (size_t j = a; j <= n; j += i)
                md[j]++;
        }
        cout << cnt << "\n";
    }
}
