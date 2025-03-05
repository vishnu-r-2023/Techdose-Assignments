class Solution {
    public int distinctPrimeFactors(int[] nums) {
        Set<Integer>res= new HashSet<>();
        for(int n: nums)
        {
            while(n%2==0)
            {
                res.add(2);
                n/=2;
            }
            for(int i=3;i<=Math.sqrt(n);i+=2)
            {
                while(n%i==0)
                {
                    res.add(i);
                    n/=i;
                }
            }
            if(n>1)
            {
                res.add(n);
            }
        }
        return res.size();
    }
}