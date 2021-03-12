#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n);

        int f, d = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > i + 1)
            {

                f = 1;
                break;
            }

            d += abs(a[i] - i + 1);
        }

        if (f == 1)
        {
            cout << "Second" << endl;
        }

        else
        {

            if (d & 1)
                cout << "First" << endl;
            else
                cout << "Second" << endl;
        }
    }
}
