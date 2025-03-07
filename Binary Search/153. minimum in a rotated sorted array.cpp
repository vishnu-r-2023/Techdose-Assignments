class Solution {
    public:
        int findMin(vector<int>& arr) {
            int ans=INT_MAX;
            int l=0;
            int h=arr.size()-1;
            while(l<=h)
            {
                int mid=l+(h-l)/2;
                if(arr[l]<=arr[h])
                {
                    ans=min(ans, arr[l]);
                }
                if(arr[l]<=arr[mid])
                {
                    ans=min(ans,arr[l]);
                    l=mid+1;
                }
                else
                {
                    ans=min(ans,arr[mid]);
                    h=mid-1;
                }
            }
            return ans;
        }
    };