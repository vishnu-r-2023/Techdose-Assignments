class Solution {
    public:
        int mod=1e9+7;
        long long fact(int n)
        {
            long long ans=1;
            for(int i=2;i<=n;i++)
            {
                ans=(ans*i)%mod;
            }
            return ans;
        }
        int numPrimeArrangements(int n) {
            int cnt=0;
            for(int i=2;i<=n;i++)
            {
                bool isPrime=true;
                for(int j=2;j<=sqrt(i);j++)
                {
                if(i%j==0)
                {
                    isPrime=false;
                    break;
                }
                }
                if(isPrime==true) cnt++;
            }
            return (fact(cnt)*fact(n-cnt))%mod;
        }
    };