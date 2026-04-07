class Solution {
public:
    int f(int i, bool hold, vector<int>& prices,int n,vector<vector<int>>& dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(i==n-1)
        {
            if(hold)
                return prices[i];
            return 0;
        }
        if(dp[i][hold]!=-1)
            return dp[i][hold];
        int b=0,s=0,nn=0;
        if(!hold)
        {
            b=-prices[i]+f(i+1,true,prices,n,dp);
        }
        else
        {
            s=prices[i]+f(i+1,false,prices,n,dp);
        }
        return dp[i][hold]=max(b,max(s,f(i+1,hold,prices,n,dp)));
        
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(0,false,prices,prices.size(),dp);
        
    }
};
/**




*/