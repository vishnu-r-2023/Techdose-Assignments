// Closest Prime Numbers in Range - LeetCode
class Solution {
public:
    vector<int>sieveofsundaram(int limit)
    {
        vector<int>primes;
        vector<bool>isPrime(limit+1,true);
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i<=sqrt(limit);i++)
        {
            if(isPrime[i])
            {
                for(int j=i*2;j<=limit;j+=i)
                {
                    isPrime[j]=false;
                }
            }
        }
        for(int i=2;i<=limit;i++)
        {
            if(isPrime[i])
            {
                primes.push_back(i);
            }
        }
        return primes;
    }
    vector<int> closestPrimes(int left, int right) {
        if(left<2)
        {
            left=2;
        }
        vector<int>primes=sieveofsundaram(sqrt(right));
        vector<int>segmentedsieve(right-left+1,true);

        for(int p:primes)
        {
            for(int d=max(p*p, (left + p - 1) / p * p);d<=right;d+=p)
            {
                segmentedsieve[d-left]=false;
            }
        }
        primes.clear();
        int count=0;
        for(int i=0;i<right-left+1;i++)
        {
            if(segmentedsieve[i])
            {
                primes.push_back(i+left);
            }
        }
        if(primes.size()<2)
        {
            return {-1,-1};
        }
        int minDiff = INT_MAX, p1 = -1, p2 = -1;
        for (int i = 1; i < primes.size(); i++) {
            if (primes[i] - primes[i - 1] < minDiff) {
                minDiff = primes[i] - primes[i - 1];
                p1 = primes[i - 1];
                p2 = primes[i];
            }
        }

        return {p1, p2};

    }
};
