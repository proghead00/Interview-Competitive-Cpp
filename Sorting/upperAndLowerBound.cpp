#include <iostream>
#include <algorithm>
using namespace std;

// first and last occurences depending on queries
int firstOcc(int a[], int n, int q)
{
    int s = 0;
    int e = n - 1;

    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (a[mid] == q)
        {
            ans = mid;
            e = mid - 1;
        }

        else if (a[mid] > q)

            e = mid - 1;

        else
            s = mid + 1;
    }

    return ans;
}

int lastOcc(int a[], int n, int q)
{
    int s = 0;
    int e = n - 1;

    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (a[mid] == q)
        {
            ans = mid;
            s = mid + 1;
        }

        else if (a[mid] > q)

            e = mid - 1;

        else
            s = mid + 1;
    }

    return ans;
}

int main()
{
    int n;

    cin >> n;

    int arr[n];

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int q;

    cin >> q;

    int query[q];

    for (size_t i = 0; i < q; i++)
    {
        cin >> query[i];
    }

    for (size_t i = 0; i < q; i++)
    {
        int first = firstOcc(arr, n, query[i]);

        int last = lastOcc(arr, n, query[i]);

        cout << first << " " << last << endl;
    }
}