#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

const int n = 1000000;
bitset<1000005> b;
vector<int> primes;

void sieve()
{

    // set all bits
    b.set(); //1,1,1,1,1,...

    b[0] = b[1] = 0; // since they're not primes

    for (long long int i = 2; i <= n; i++)
    {
        if (b[i])
        {
            primes.push_back(i);

            // make multiples of the current prime 0
            for (long long int j = i * i; j <= n; j = j + i)
            {
                b[j] = 0;
            }
        }
    }
}

bool isPrime(long long num)
{
    if (num <= n)
    {
        return b[num] == 1 ? true : false; //O(1)
    }

    for (long long int i = 0; primes[i] * (long long)primes[i] <= num; i++)
    {
        if (num % primes[i] == 0)
            return false;
    }

    return true;
}

int main()
{

    sieve();

    if (isPrime(3267000013))
    {
        cout << "PRIME" << endl;
    }

    else

        cout << "NOT PRIME" << endl;
}