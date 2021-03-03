#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int s;

        cin >> s;

        int q[s];
        for (size_t i = 0; i < s; i++)
        {
            cin >> q[i]; // duration of intro of each season
        }

        int e[s];
        int len = sizeof(e) / sizeof(e[0]);

        int l[len];

        int total = 0;

        for (size_t i = 0; i < s; i++)
        {

            cin >> e[i]; // no of eps in the season
            len = sizeof(e) / sizeof(e[0]);

            for (size_t k = 0; k < len; k++)
            {
                l[k] = -1;
            }

            for (size_t j = 0; j < len; j++)
            {
                total = 0;
                cin >> l[j];

                if (e[j] == 1)
                {
                    total = 1;
                    total = total * l[j];
                }
                else
                {
                    total += l[0] + (l[j] - q[j]);
                }
            }
        }

        cout << total << endl;
    }
}