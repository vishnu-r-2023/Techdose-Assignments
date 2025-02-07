// 1734. Decode XORed Permutation

class Solution {
public:
    int xorfulton(int n)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans^=i;
        }
        return ans;
    }
    vector<int> decode(vector<int>& encoded) {
        vector<int>res;
        int xorfull=xorfulton(encoded.size()+1);
        int xorenc=0;
        for(int i=0;i<encoded.size();i+=2)
        {
            xorenc^=encoded[i];
        }
        int element= xorenc^xorfull;
        res.push_back(element);
        for(int i=encoded.size()-1;i>=0;i--)
        {
            element^=encoded[i];
            res.push_back(element);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
