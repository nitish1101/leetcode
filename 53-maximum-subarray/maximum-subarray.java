class Solution {
    public int maxSubArray(int[] nums) {
        int n=nums.length;
        int ans=0;
        int s=0;
        int maxi=-100000;
        for(int i=0;i<n;i++)
            maxi=Math.max(maxi,nums[i]);
        if(maxi<0)
            return maxi;
        for(int i=0;i<n;i++)
        {
            s=s+nums[i];
            if(s<0)
                s=0;
            else{
                ans=Math.max(ans,s);
                System.out.println(ans);
            }
        }
        return ans;
        
    }
}