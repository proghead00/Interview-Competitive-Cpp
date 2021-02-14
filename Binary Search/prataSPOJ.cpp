#include <iostream>
#include <climits>
using namespace std;
bool isPossible(int ranks[], int p, int cooks, int mid)
{
    int count1 = 0, i;

    for (int i = 0; i < cooks; i++)
    {
        int j = 1;
        int sum = 0;
        while (sum <= mid)
        {
            sum = sum + j * ranks[i];
            count1++;
            j++;
        }
        count1--;
    }
    if (count1 >= p)
    {
        return true;
    }
    else
        return false;
}

int findMin(int ranks[], int p, int cooks)
{
    int s = 0, ans = 0;
    int e = 10000007;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (isPossible(ranks, p, cooks, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans;
}

int main()
{
    int t, p, cooks;
    cin >> t;
    while (t--)
    {
        cin >> p;
        cin >> cooks;

        int ranks[cooks];

        for (int i = 0; i < cooks; i++)
        {
            cin >> ranks[i];
        }

        cout << findMin(ranks, p, cooks) << endl;
    }
    return 0;
}