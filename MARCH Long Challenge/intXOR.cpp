#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int C;
        cin >> C;

        int total_bits = (int)log2(C) + 1;

        int A = pow(2, total_bits - 1) - 1;

        int B = A ^ C;

        int p = A * B;

        cout << p << endl;
    }
}