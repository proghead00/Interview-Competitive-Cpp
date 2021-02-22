#include <iostream>
using namespace std;

int main()
{

    int ans = 1;

    int a, n;
    cin >> a >> n;

    while (n > 0)
    {
        int last_bit = (n & 1);

        if (last_bit)
        {
            ans *= a;
        }

        a = a * a;
        n = n >> 1;
    }
    cout << ans << endl;
}