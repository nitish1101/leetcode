class Solution {
public:

    int f(int i, int k,unordered_map<int,int>& mp, vector<int>& stones, vector<vector<int>>& dp)
    {
        if(i==mp.size()-1)
            return 1;

        if(dp[i][k]!=-1)
            return dp[i][k];

        bool result =false;
        for(int x=k-1;x<=k+1;x++)
        {
            if(x>0)
            {
                int next= stones[i]+x;
                if(mp.find(next)!=mp.end()) {
                    result = result || f(mp[next],x,mp,stones,dp);
                }
            }
        }
        return dp[i][k]=result;
    }

    bool canCross(vector<int>& stones) {

        vector<vector<int>> dp(stones.size(), vector<int>(2000,-1));

        if(stones[1]!=1)
            return false;

        unordered_map<int,int> mp;
        for(int i=0;i<stones.size();i++)
            mp[stones[i]]=i;

        return f(1,1,mp,stones,dp);
    }
};


/***
 



*/