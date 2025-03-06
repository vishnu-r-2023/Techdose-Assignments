class Solution {
    public:
        int lowerbound(vector<int>arr,int target)
        {
            int l=0,h=arr.size()-1;
            while(l<=h)
            {
                int mid=l+(h-l)/2;
                if(arr[mid]==target)
                {
                    h=mid-1;
                }
                else if(arr[mid]>target) h=mid-1;
                else l=mid+1;
            }
            return l<arr.size() && arr[l]==target?l:-1;
        }
        int upperbound(vector<int>arr,int target)
        {
            int l=0,h=arr.size()-1;
            while(l<=h)
            {
                int mid=l+(h-l)/2;
                if(arr[mid]==target)
                {
                    l=mid+1;
                }
                else if(arr[mid]>target) h=mid-1;
                else l=mid+1;
            }
            return h>=0 && arr[h]==target?h:-1;
        }
        vector<int> searchRange(vector<int>& nums, int target) {
            if(nums.size()==0)
            {
                return {-1,-1};
            }
            int l=lowerbound(nums,target);
            int h=upperbound(nums,target);
            return {l,h};
        }
    };