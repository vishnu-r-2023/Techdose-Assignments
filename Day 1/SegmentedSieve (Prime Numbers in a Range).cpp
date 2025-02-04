#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> sieveofsundaram(int limit)
{
    vector<int> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= sqrt(limit); i++)
    {
        if (isPrime[i])
        {
            for (int j = i * 2; j <= limit; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= limit; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}

vector<int> segmentedsieve(int L, int R)
{
    vector<int> primes = sieveofsundaram(sqrt(R));
    vector<bool> segmentedSieve(R - L + 1, true);

    for (int p : primes)
    {
        for (int d = L / p; d <= R/p; d++)
        {
            if (p * d >= L)
            {
                segmentedSieve[p * d - L] = false;
            }
        }
    }

    primes.clear();
    for (int i = 0; i < R - L + 1; i++)
    {
        if (segmentedSieve[i])
        {
            primes.push_back(i + L);
        }
    }
    return primes;
}

int main()
{
    int L,R;
    cin>>L>>R;
    vector<int> primes = segmentedsieve(L, R);

    for (int prime : primes)
    {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
