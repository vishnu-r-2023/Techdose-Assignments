//201. Bitwise AND of Numbers Range

class Solution {
    public:
    
        int rangeBitwiseAnd(int left, int right) {
            int count=0;
            while(left!=right)
            {
                left>>=1;
                right>>=1;
                count++;
            }
            int ans = left<<count;
            return ans;
        }
    };