#include <iostream>
using namespace std;

void merge(int *a, int s, int e)
{
    int mid = s + (s + e) / 2;

    int i = s;
    int j = mid + 1;

    int k = s;

    int temp[100];

    while (i <= mid && j <= e)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];
        }

        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
    {
        temp[k++] = a[i++];
    }

    while (j <= e)
    {
        temp[k++] = a[j++];
    }

    // copying to og array
    for (size_t i = s; i <= e; i++)
    {
        a[i] = temp[i];
    }
}

void ms(int *a, int s, int e)
{
    //1. base case
    if (s >= e)
    {
        return;
    }

    //2. divide
    int mid = s + (s + e) / 2;

    // recursively sort
    ms(a, s, mid);
    ms(a, mid + 1, e);

    // merge 2 arrays
    merge(a, s, e);
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
    int s = 0;
    int e = n - 1;

    ms(a, s, e);

    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}