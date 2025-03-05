class Solution {
    public:
        bool isPrime(long long n)
        {
            if(n==0 || n==1) return false;
            if(n==2) return true;
            for(int i=2;i<=sqrt(n);i++)
            {
                if(n%i==0)
                {
                    return false;
                }
            }
            return true;
        }
    
        bool reverse(long long n) {
            string num = to_string(n);
            int start = 0, end = num.length() - 1;
            while (start < end) {
                if (num[start] != num[end]) return false;
                start++;
                end--;
            }
            return true;
        }
    
        int primePalindrome(long long n) {
            if (n >= 8 && n <= 11) return 11;
            
            while (true) {
                if (isPrime(n) && reverse(n)) return n;
                n++;
                if (n > 11 && to_string(n).length() % 2 == 0) 
                    n = pow(10, to_string(n).length());
            }
        }
    };