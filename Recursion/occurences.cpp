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