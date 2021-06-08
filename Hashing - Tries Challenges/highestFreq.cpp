#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    map<int, int> m; //ELement value-Freq pair
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        m[x]++;
    }

    int maxFreq = 0;
    int ans = 0;
    for (auto it : m)
    {
        if (it.second > maxFreq)
        {
            maxFreq = it.second;
            ans = it.first;
        }
    }
    for (auto it : m)
    {
        cout << it.first << " -> " << it.second << endl;
    }
    cout << ans;

    return 0;
}
