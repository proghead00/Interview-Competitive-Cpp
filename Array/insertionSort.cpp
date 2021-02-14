#include <iostream>
using namespace std;

void insSort(int a[], int n)
{

    for (int i = 1; i < n - 1; i++)
    {
        int e = a[i];

        int j = i - 1;

        while (j >= 0 && a[j] > e)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = e;
    }
}

int main(int argc, char)
{

    int n, key;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    insSort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i];
}