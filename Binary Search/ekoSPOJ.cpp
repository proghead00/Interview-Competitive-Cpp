#include <iostream>
using namespace std;

bool check(int mid, int height[], int n, int m)
{
    int cut_sum = 0;

    for (int i = 0; i < n; i++)
    {

        if (height[i] > mid)
            cut_sum += height[i] - mid;
    }

    if (cut_sum < m)
    {
        return false;
    }

    else

        return true;
}
int main()
{
    int n, m;

    cin >> n >> m;

    int height[n];

    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    int s = 0;

    int max2 = height[0];
    for (int i = 0; i < n; i++)
    {
        max2 = max(max2, height[i]);
    }

    int e = max2;
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (check(mid, height, n, m))
        {
            ans = mid;

            s = mid + 1;
        }

        else
            e = mid - 1;
    }

    cout << ans << endl;
}