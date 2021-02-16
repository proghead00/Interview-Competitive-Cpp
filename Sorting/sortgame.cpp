#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool myCompare(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
        return a.first < b.first; // names in lexicographic order when salaries are equal

    return a.second > b.second; // descending
}

int main()
{
    int x, n, i;
    cin >> x;
    pair<string, int> a[100000];
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i].first;  // employee name i/p
        cin >> a[i].second; // salary i/p
    }
    sort(a, a + n, myCompare);

    for (i = 0; i < n and a[i].second >= x; i++)
    {
        cout << a[i].first << " " << a[i].second << endl;
    }

    return 0;
}