#include <iostream>
using namespace std;

int main()
{
    int n;

    cin >> n;

    int arr[n];

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;

    cin >> x;

    int s = 0, e = n - 1;

    int ans = -1;
    while (s <= e)

    {
        int mid = (s + e) / 2;

        if (arr[mid] == x)
        {
            cout << mid;
            return 0;
        }

        // first part
        else if (arr[s] < arr[mid])
        {
            // 2 cases -> element on the left or right

            if (x >= arr[s] and x <= arr[mid])
            {
                e = mid - 1;
            }
            else
                s = mid + 1;
        }

        else if (arr[s] > arr[mid])
        {
            if (x >= arr[mid] and x <= arr[e])
                s = mid + 1;

            else
                e = mid - 1;
        }
    }

    return -1;
}