#include <iostream>
using namespace std;

int main()
{

    int t;

    int n, k;

    cin >> t;

    int scr = 0;
    while (t--)
    {
        cin >> n >> k;

        int a[k];

        for (size_t i = 0; i < k; i++)
        {
            cin >> a[i];
        }

        string s;

        for (size_t i = 0; i < n; i++)
        {
            scr = 0;
            cin >> s;

            for (size_t j = 0; j < 2; j++)
            {

                if (s[j] - '0' == 1)
                {
                    scr += a[j];
                }

                else if (s[j] - '0' == 0)
                    scr += 0;
            }
            cout << scr << endl;
        }
    }
}