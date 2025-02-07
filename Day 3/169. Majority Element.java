// 169. Majority Element

class Solution {
    public int majorityElement(int[] nums) {
        int morethan=nums.length/2;
        int maximum=0;
        HashMap<Integer,Integer>mp= new LinkedHashMap<>();
        for(int i=0;i<nums.length;i++)
        {
            int number=nums[i];
            mp.put(number,0);
        }
        for(int i=0;i<nums.length;i++)
        {
            int key=nums[i];
            int val=mp.get(nums[i]);
            val+=1;
            mp.put(key,val);
        }
        for(int i=0;i<nums.length;i++)
        {
            int key=nums[i];
            int val=mp.get(key);
            maximum=Math.max(maximum,val);
        }
        System.out.print(mp);
        int ans=0;
        for(Map.Entry<Integer,Integer>entry:mp.entrySet())
        {
            if(entry.getValue().equals(maximum))
            {
                ans=entry.getKey();
                break;
            }
        }
        return ans;
    }
}