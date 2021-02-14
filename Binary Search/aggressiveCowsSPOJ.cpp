#include <iostream>
using namespace std;

bool canWePlaceCows(int stalls[], int n, int c, int min_sep)
{
    int last_cow = stalls[0];
    int cnt = 1;

    for (int i = 1; i < n; i++)
    {

        if ((stalls[i] - last_cow) >= min_sep)
        {

            last_cow = stalls[i];
            cnt++;

            if (cnt == c)
            {
                return true;
            }
        }
    }

    return false;
}
int main()
{
    int n = 5;    // no of stalls
    int cows = 3; // no of cows

    int stalls[] = {1, 2, 4, 8, 9}; // taking sorted array

    int s = 0;
    int e = stalls[n - 1] - stalls[0];

    int ans = 0;
    while (s <= e)

    {
        int mid = (s + e) / 2;

        bool kek = canWePlaceCows(stalls, n, cows, mid);
        if (kek)
        {

            ans = mid;

            // to search if there are larger numbers
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    cout << ans;
    return 0;
}
