// SEGMENTED SIEVE

#include <iostream>
#include <vector>
using namespace std;

#define N 100000 // N = sqrt(n)

vector<int> primes; //will store prime nos. -> 2,3,5,7,...

int p[N] = {0};

// 0 -> not prime
// 1 -> prime

void sieve()
{

    for (size_t i = 2; i <= N; i++)
    {
        if (p[i] == 0)
        {
            primes.push_back(i);

            // mark on multiples as NON PRIME
            for (size_t j = i * i; j <= N; j++)
            {
                p[j] = 1; // not prime
            }
        }
    }
}

int main()
{

    sieve(); // building sieve only once for all queries

    int t;
    cin >> t;

    while (t--)
    {

        int n, m;

        cin >> m >> n;

        bool segment[n - m + 1];

        for (size_t i = 0; i < n - m + 1; i++)
        {
            segment[i] = 0;
        }

        for (auto x : primes)
        {
            if (x * x > n)
            {
                break; // stop loop if rermaining prime nos aren't needed
            }

            int start = (m / x) * x;

            if (x >= m and x <= n)
            {
                start = 2 * x;
            }

            // mark multiples of x  as non prime
            for (size_t i = start; i <= n; i += x)
            {
                segment[i - m] = 1;
            }
        }

        for (size_t i = m; i <= n; i++)
        {
            if (segment[i - m] == 0 and i != 1)
            {
                cout << i << endl;
            }
        }

        cout << endl;
    }
}
