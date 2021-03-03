#include <iostream>
using namespace std;

int partition(int *a, int s, int e)
{
    int pivot = a[e];

    int pIndex = s; // initially at start

    for (size_t i = s; i < e; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);

            pIndex++;
        }
    }

    swap(a[pIndex], a[e]);

    return pIndex;
}

void quicksort(int a[], int start, int end)
{

    if (start >= end)
    {
        return;
    }

    int pindex = partition(a, start, end);
    quicksort(a, start, pindex - 1);
    quicksort(a, pindex + 1, end);
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

    quicksort(a, 0, n - 1);

    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}