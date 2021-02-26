#include <iostream>
using namespace std;

int ith_bit(int n, int i)
{

    return (n & (1 << i)) > 0 ? 1 : 0;
}

int set_ith_bit(int n, int i)
{
    return n | (1 << i);
}

int clear_ith_bit(int n, int i)
{

    int mask = ~(1 << i);
    n = (n & mask);

    return n;
}

int update_ith_bit(int n, int v, int i)
{
    int mask = ~(1 << i);

    int cleared_n = n & mask;

    n = cleared_n | (v << i);
    return n;
}

int clear_range_bits(int n, int i)
{
    int mask = (-1 << i);
    n = (n & mask);

    return n;
}

int clear_i_to_j(int n, int i, int j)
{
    int ones = ~0;

    int a = ones << j + 1;

    int b = (1 << i) - 1;

    int mask = a | b;

    int ans = n & mask;

    return ans;
}

int count_set_bits(int n)
{
    while (n > 0)
    {
        /* code */
    }
}

int main()
{

    int n, i, j;

    cin >> n >> i >> j;

    int update = clear_i_to_j(n, i, j);

    cout << update << endl;
}
