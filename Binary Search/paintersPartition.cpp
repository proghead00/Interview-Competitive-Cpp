#include <iostream>
using namespace std;

bool isAValidConfig(int b[], int k, int n, int mid)
{
    int painters = 1;
    int curr_board = 0;

    for (int i = 0; i < n; i++)
    {
        if (curr_board + b[i] > mid)
        {
            painters++;

            curr_board = b[i]; //assigning from the next book to the next student

            if (painters > k)
            {
                return false;
            }
        }

        else
            curr_board += b[i]; // adding another book
    }
    return true;
}

int main()
{

    int k, n;

    cin >> k;

    cin >> n;

    int boards[n];
    int st = 0, MAX = 0; // starting index should be the minimum element since it's the miminum time

    for (int i = 0; i < n; i++)
    {
        cin >> boards[i];

        MAX = max(MAX, boards[i]);
    }
    st = MAX;

    int e;

    for (int i = 0; i < n; i++)
    {

        e += boards[i];
    }

    int ans;

    while (st <= e)
    {
        int mid = (st + e) / 2;

        if (isAValidConfig(boards, k, n, mid))
        {
            ans = mid;

            e = mid - 1;
        }

        else
            st = mid + 1;
    }

    cout << ans << endl;
}