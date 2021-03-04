#include <iostream>
using namespace std;

int merge(int *a, int s, int e)
{
    int mid = s + (s + e) / 2;
    int i = s;
    int j = mid + 1;

    int k = s;

    int temp[100000000];
    int c = 0;

    while (i <= mid && j <= e)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];

            // if the numbers aren't in sorted order
            c += mid - i + 1;
        }
    }

    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= e)
    {
        temp[k++] = a[j++];
    }

    for (size_t i = s; i <= e; i++)
    {
        a[i] = temp[i];
    }

    return c;
}

int inv(int *a, int s, int e)
{
    if (s >= e)
        return 0;

    int mid = (s + e) / 2;

    int x = inv(a, s, mid);     // no of inv in first half
    int y = inv(a, mid + 1, e); // second half

    int z = merge(a, s, e); // cross inv

    return x + y + z;
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << inv(a, 0, n - 1) << endl;
}