#include <iostream>
using namespace std;

void prime_sieve(int *p)
{

    // first make all odd numbers prime

    for (size_t i = 3; i <= 1000000; i += 2)
    {
        p[i] = 1;
    }

    // sieve
    for (size_t i = 3; i <= 1000000; i++)
    {
        // if curr number is not marked, it is prime

        if (p[i] == 1)
        {
            // make all the multiples of i as NOT prime

            for (size_t j = i * i; j <= 1000000; j += i)
            {
                p[j] = 0;
            }
        }
    }

    // special case
    p[2] = 1;        // since 2 is prime
    p[0] = p[1] = 0; // not prime
}

int main()
{
    int p[1000000] = {0};
    prime_sieve(p);

    int csum[1000000] = {0};

    // precompute primes upto i
    for (size_t i = 1; i <= 1000000; i++)
    {
        csum[i] = csum[i - 1] + p[i];
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b;

        cin >> a >> b;

        cout << csum[b] - csum[a - 1] << endl;
    }
}