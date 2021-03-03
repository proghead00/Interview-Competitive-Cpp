#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int c, d;

        cin >> d >> c;

        int a[3];
        int b[3];

        cin >> a[0] >> a[1] >> a[2];

        cin >> b[0] >> b[1] >> b[2];

        int sa = 0, sb = 0;

        int wc = 0, woc = 0;

        sa = a[0] + a[1] + a[2];
        sb = b[0] + b[1] + b[2];
        int total = sa + sb;

        wc = 0;
        woc = sa + sb + (2 * d);

        if (sa >= 150 && sb < 150)
        {
            wc = total + c + d;
        }

        else if (sa < 150 && sb >= 150)
        {
            wc = total + c + d;
        }

        else if (sa >= 150 && sb >= 150)
        {
            wc = total + c;
        }
        else if (sa < 150 && sb < 150)
            wc = woc;

        if (wc < woc)
            cout << "YES" << endl;

        else
            cout << "NO" << endl;
    }
}