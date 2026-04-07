class Solution {
    public int firstMissingPositive(int[] nums) {
        
        int n=nums.length;
        //1.....n+1;
        for(int i=0;i<n;i++)
            if(nums[i]<0)
                nums[i]=0;

        for(int i=0;i<n;i++)
        {
            int t=Math.abs(nums[i]);
            
            if(t-1 < n && t-1 >= 0) {
                if(nums[t-1] > 0)
                    nums[t-1]=-1*nums[t-1];
                else if(nums[t-1]==0)
                    nums[t-1]=-(n+1);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(nums[i-1] >= 0)
                return i;
        }
        return (n+1);       
    }
}