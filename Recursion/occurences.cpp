#include <iostream>
using namespace std;

int first_occ(int *a, int n, int key)
{

    if (n == 0)
    {
        return -1;
    }

    if (a[0] == key)
        return 0;

    int i = first_occ(a + 1, n - 1, key);

    if (i == -1)
    {
        return -1;
    }

    return i + 1;
}

int last_occ(int *a, int n, int key)

{

    if (n == 0)
    {
        return -1;
    }

    int i = last_occ(a + 1, n - 1, key);
    if (i == -1)
    {
        if (a[0] == key)
        {
            return 0;
        }

        else
            return -1;
    }

    return i + 1;
}

void all_occurences(int *a, int i, int n, int key)
{
    if (i == n)
        return;

    if (a[i] == key)
    {
        cout << i << " ";
    }

    all_occurences(a, i + 1, n, key);
}

int store_occurences(int *a, int i, int n, int key, int *out, int j)
{
    if (i == n)
    {
        return j;
    }

    if (a[i] == key)
    {
        out[j] = i;
        return store_occurences(a, i + 1, n, key, out, j);
    }
    return store_occurences(a, i + 1, n, key, out, j);
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

    int k;
    cin >> k;

    int i = last_occ(a, n, k);

    cout << i << endl;
}