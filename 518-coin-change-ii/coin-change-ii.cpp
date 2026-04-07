class Solution {
public:
    int f(int i, vector<int>& arr,int target,vector<vector<int>>& dp)
    {
        if(target == 0)
            return 1;
        if(i==arr.size() || target < 0)
            return 0;
        if(dp[i][target]!=-1)
            return dp[i][target];

        return dp[i][target]=f(i,arr,target-arr[i],dp)+f(i+1,arr,target,dp);
    }


    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return f(0,coins,amount,dp);
        
    }
};
