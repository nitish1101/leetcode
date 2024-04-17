class Solution {
public:
    int f(int i,bool prev, vector<int>& nums, int n, vector<vector<int>>& dp)
    {
        if(i==n-1){
            if(!prev)
                return nums[i];
            return 0;
        }
        if(dp[i][prev]!=-1)
            return dp[i][prev];


        int rob=0, not_rob=0;
        if(!prev)
            rob=nums[i] + f(i+1,true,nums,n,dp);
        not_rob=0+f(i+1,false,nums,n,dp);
        return dp[i][prev]=max(rob,not_rob);
    }
    int rob(vector<int>& nums) {
        /**
        i, prev
        rob or not rob
        last house to be robbed if prev=0
        memoize
         */
         int n=nums.size();
         vector<vector<int>> dp(n,vector<int>(2,-1));
         return f(0,false,nums,n,dp);      
    }
};