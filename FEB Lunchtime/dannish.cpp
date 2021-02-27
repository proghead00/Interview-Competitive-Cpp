#include <iostream>
using namespace std;

int main()
{

    long long int t;
    cin >> t;

    while (t--)
    {
        long long int a[10];

        for (size_t i = 0; i < 10; i++)
        {
            cin >> a[i];
        }

        long long int k;

        cin >> k;

        int i;
        for (i = 10; i >= 1; i--)
        {
            if (k != 0 && a[i - 1] != 0)
            {
                if (a[i - 1] >= k)
                {
                    a[i - 1] -= k;
                    k = 0;
                }

                else
                {
                    k -= a[i - 1];
                    a[i - 1] = 0;
                }
            }

            if (k == 0)
            {
                break;
            }
        }

        for (size_t j = i; j >= 1; j--)
        {
            if (a[j - 1] != 0)
            {
                cout << j << endl;
                break;
            }
        }
    }
}