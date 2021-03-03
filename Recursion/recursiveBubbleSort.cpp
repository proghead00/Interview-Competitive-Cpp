#include <iostream>
using namespace std;

void rbubble(int *a, int n, int j)

{
    if (n == 1)
    {
        return;
    }

    if (j == n - 1)
    {
        rbubble(a, n - 1, 0);
        return;
    }

    if (a[j] > a[j + 1])
    {
        swap(a[j], a[j + 1]);
    }

    rbubble(a, n, j + 1);

    return;
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

    rbubble(a, n, 0);

    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}