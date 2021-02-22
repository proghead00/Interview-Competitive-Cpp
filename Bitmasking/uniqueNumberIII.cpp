#include <iostream>
using namespace std;

int main()
{
    int c[64] = {0};

    int n, num;

    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        cin >> num;

        int j = 0;

        while (num > 0)
        {
            int last_bit = (num & 1);

            c[j] += last_bit;

            j++;

            num = num >> 1;
        }
    }

    int p = 1, ans = 0;

    for (size_t i = 0; i < 64; i++)
    {
        c[i] %= 3;
        ans += (c[i] * p);
        p++;
    }

    cout << ans << endl;
}
