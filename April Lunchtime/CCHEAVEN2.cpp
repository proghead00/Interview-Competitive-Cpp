#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;

        int a1 = 0;
        int a0 = 0;

        cin >> n >> s;

        int k = 0;

        for (size_t i = 0; i < n; i++)
        {
            (s[i] == '0') ? a0++ : a1++;

            if (a1 >= a0)
            {
                k = 1;
                break;
            }
        }

        if (k == 0)
        {
            cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }
}
