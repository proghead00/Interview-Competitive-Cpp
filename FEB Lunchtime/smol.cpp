#include <iostream>
using namespace std;

int main()
{

    long long t;

    cin >> t;

    while (t--)
    {

        long long n, k;

        cin >> n >> k;

        while (n >= k)
        {

            n = n - k;
        }
        cout << n << endl;
    }
}