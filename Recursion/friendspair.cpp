#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 1)
        return 1;

    return n * fact(n - 1);
}
int ways(int n)
{
    if (n == 1)
        return 1;

    if (n == 2)
    {
        return 2;
    }

    return (ways(n - 1) + ways(fact(n - 1) / fact(n - 2)));
}

int main()
{
    int n;

    cin >> n;

    cout << ways(n) << endl;
}