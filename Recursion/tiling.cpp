#include <iostream>
using namespace std;

int ways(int n)
{
    if (n == 0)
        return 0;

    if (n < 4)
    {
        return 1; //1 way
    }

    if (n >= 4)
    {
        return (ways(n - 1)) + (ways(n - 4));
    }
}
int main()

{
    // wall size: 4 x N
    // tile size: 1,4 or 4,1

    int n;

    cin >> n;

    int w = ways(n);

    cout << w << endl;
}