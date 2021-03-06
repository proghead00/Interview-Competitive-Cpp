#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int c = 0;

        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] == '1' && s[i] != s[i + 1])
            {
                c++;
            }
        }

        cout << c << endl;
    }
}