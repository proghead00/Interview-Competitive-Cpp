#include <iostream>
#define m 1000000007
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long s = 0;
    //  long long m = 10 ^ 9 + 7;

    for (size_t i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        s = (s + x + m) % m;
    }

    long long q;
    cin >> q;

    while (q--)
    {
        s = (2 * s) % m;
        cout << s << endl;
    }
}
