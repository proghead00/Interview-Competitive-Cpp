#include <iostream>
using namespace std;

int main()
{
    int n, h, x;

    cin >> n >> h >> x;

    int t[n];

    for (int i = 0; i < n; i++)
        cin >> t[i];

    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if (x + t[i] >= h)

        {
            cout << "yes" << endl;
            return 0;
        }
    }

    cout << "no" << endl;
}
