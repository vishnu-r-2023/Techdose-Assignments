#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> sieveofEratosthenes(int limit)
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

int main()
{
    int limit;
    cin>>limit;
    vector<int> primes = sieveofEratosthenes(limit);

    for (int prime : primes)
    {
        cout << prime << " ";
    }
}
