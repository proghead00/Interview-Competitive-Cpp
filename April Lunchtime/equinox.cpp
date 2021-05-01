#include <iostream>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        long n, a, b;

        cin >> n >> a >> b;
        long cs = 0, ca = 0;

        while (n--)
        {
            string s;
            cin >> s;

            if (s[0] == 'E' || s[0] == 'Q' || s[0] == 'U' || s[0] == 'I' || s[0] == 'N' || s[0] == 'O' || s[0] == 'X')
                cs+=a;

            else
                ca+=b;

        }
        if (cs > ca)
            cout << "SARTHAK" << endl;

        else if (ca > cs)
            cout << "ANURADHA" << endl;

        else
            cout << "DRAW" << endl;
    }
}
