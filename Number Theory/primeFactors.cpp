#include <iostream>
#include <vector>
using namespace std;

// 0 -> NOT PRIME || 1 -> PRIME

vector<int> primeSieve(int *p, int n)

{
    p[0] = p[1] = 0;
    p[2] = 1;

    // odd nos. -> prime
    for (size_t i = 3; i <= n; i += 2)
    {
        p[i] = 1;
    }

    // sieve to mark non prime nos as 0

    // 1. optimization -> iterate over odd nos
    for (size_t i = 3; i <= n; i += 2)
    {

        if (p[i])
        {
            // mark all multiples of that no. as NOT PRIME
            // 2. optimization -> take a jump of 2i starting from i * i

            for (size_t j = i * i; j <= n; j += 2 * i)
            {
                p[j] = 0;
            }
        }
    }

    vector<int> primes;

    primes.push_back(2);

    for (size_t i = 3; i <= n; i += 2)
    {
        if (p[i])
        {
            primes.push_back(i);
        }
    }

    return primes;
}

vector<int> factorize(int m, vector<int> &primes)
{
    vector<int> factors;
    factors.clear(); // creates empty vector

    int i = 0;
    int p = primes[0];

    while (p * p <= m)
    {
        if (m % p == 0)
        {
            factors.push_back(p);

            while (m % p == 0)
            {
                m = m / p; // if m =12 -> next time, m=6...and so on
            }
        }

        // go to next position
        i++;
        p = primes[i]; // primes will have now 3, 5 ,7 ...
    }

    // the last of m, if it's a prime no
    if (m != 1)
    {
        factors.push_back(m);
    }

    return factors;
}

int main()
{
    int N = 1000000;
    int p[N] = {0};

    for (size_t i = 0; i < N; i++)
    {
        p[i] = 0;
    }

    vector<int> primes = primeSieve(p, 10000);

    int t;
    cin >> t;

    while (t--)
    {
        int num;
        cin >> num;

        vector<int> factors = factorize(num, primes);

        for (auto f : factors)
        {
            cout << f << " " << endl;
        }
    }
}
