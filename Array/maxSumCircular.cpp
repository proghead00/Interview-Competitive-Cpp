#include <iostream>
#include <climits>
using namespace std;

int main(int argc, char)
{
    int n;

    cin >> n;

    int a[n];
    int b[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = -a[i];
    }

    // kadane's -> max sum
    int cs = 0, ms = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] < 0)
            cs = 0;

        else
            cs += b[i];

        ms = max(cs, ms);
    }

    // array sum
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += b[i];
    }

    int originalMAX = -(s - ms);

    cout << originalMAX << endl;
}