class Solution {
    public:
        void merge(vector<int>&nums,int l,int h,int mid)
        {
            int left=l;
            int right=mid+1;
            vector<int>temp;
            while(left<=mid && right<=h)
            {
                if(nums[left]<=nums[right])
                {
                    temp.push_back(nums[left]);
                    left++;
                }
                else
                {
                    temp.push_back(nums[right]);
                    right++;
                }
            }
            while(left<=mid)
            {
                temp.push_back(nums[left]);
                left++;
            }
            while(right<=h)
            {
                temp.push_back(nums[right]);
                right++;
            }
    
            for(int i=l;i<=h;i++)
            {
                nums[i]=temp[i-l];
            }
        }
        void mergeSort(vector<int>&nums,int l,int h)
        {
            if(l>=h) return;
            int mid=l+(h-l)/2;
            mergeSort(nums,l,mid);
            mergeSort(nums,mid+1,h);
            merge(nums,l,h,mid);
        }
        vector<int> sortArray(vector<int>& nums) {
            
            int n=nums.size();
    
            // MERGE SORT
    
            int l=0,h=n-1;
            mergeSort(nums,l,h);
    
            return nums;
    
        }
    };