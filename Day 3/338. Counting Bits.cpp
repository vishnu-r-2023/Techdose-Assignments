// 338. Counting Bits

class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int> a;
            for(int i=0;i<=n;i++)
                a.push_back(__popcount(i));
            return a;
        }
    };