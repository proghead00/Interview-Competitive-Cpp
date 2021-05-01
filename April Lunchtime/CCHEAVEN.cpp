#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int l;
        cin >> l;

        string s;
        cin >> s; //0 and 1

        int sd = 0;
        for (size_t i = 0; i < l; i++)
        {
            sd += s[i] - '0';
        }

        if (((sd * 100) / l) >= 50)
        {
            cout << "YES" << endl;
        }

        else
        {
            cout << "NO" << endl;
        }
    }
}
