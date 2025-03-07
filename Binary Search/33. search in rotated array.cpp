class Solution {
    public:
        int search(vector<int>& arr, int target) {
            int n=arr.size();
            //sort(arr.begin(),arr.end());
            int l=0;
            int h=n-1;
            while(l<=h)
            {
                int mid=l+(h-l)/2;
                if(arr[mid]==target)
                {
                    return mid;
                }
                if(arr[l]<=arr[mid])
                {
                if(arr[l]<=target && arr[mid]>=target)
                {
                    h=mid-1;
                }
                else
                {
                    l=mid+1;
                }
                }
                if(arr[h]>=arr[mid])
                {
                    if(arr[h]>=target && arr[mid]<=target)
                    {
                        l=mid+1;
                    }
                    else
                    {
                        h=mid-1;
                    }
                }
            }
            return -1;
        }
    };