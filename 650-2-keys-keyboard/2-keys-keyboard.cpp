class Solution {
public:
    int f(int curr, int c, int n, vector<vector<int>>& dp) // minsteps to have A n times if currently have count As on the screen and have copied c As.
    {
        if(curr==n)
            return 0;
        if(curr > n)
            return 1001;
        if(dp[curr][c]!=-1)
            return dp[curr][c];
        
        return dp[curr][c] = min(1+f(curr+c, c ,n,dp),2+f(curr+curr,curr,n,dp));
    
    }

    int minSteps(int n) {

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        if(n==1)
            return 0;
        return 1+f(1,1,n,dp);
        
    }
};


