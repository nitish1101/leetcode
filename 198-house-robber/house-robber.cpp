class Solution {
public:

    int f(int i, vector<int>& nums, vector<int>& dp)
    {
        if(i>=nums.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int p=nums[i]+f(i+2,nums, dp);
        int np=f(i+1,nums,dp);
        return dp[i]=max(p,np);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(0,nums,dp);
    }
};


/***
1,2,3,1

no adj

max money


f(i,nums,dp)


p = nums[i] + f(i+2,nums)
np = f(i+1, nums)

dp[i]=max(p,np);




*/