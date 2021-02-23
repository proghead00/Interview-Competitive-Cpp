#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int res = 0;

    int a[1000005];

    int num;
    for (size_t i = 0; i < n; i++)
    {
        cin >> num;

        a[i] = num;

        res = res ^ num;
    }

    int temp = res;
    int pos = 0;

    while ((temp & 1) != 1)
    {
        temp = temp >> 1; // rightshift till 1 is found
        pos++;
    }

    int mask = (1 << pos); // first set bit is at pos

    // numbers with set bits at pos:

    int x = 0, y = 0;
    for (size_t i = 0; i < n; i++)
    {
        if ((a[i] & mask) > 0) // take in nos. with set bits at pos
        {
            x = x ^ a[i];
        }
    }

    y = res ^ x;

    cout << (min(x, y)) << " " << max(x, y);
}