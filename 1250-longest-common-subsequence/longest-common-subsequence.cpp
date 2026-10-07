class Solution {
public:

    int f(int i, int j, string& s1,string& s2,vector<vector<int>>& dp)
    {
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];

        int match=0,not_match=0;
        if(s1[i]==s2[j])
        {
            match= 1+(f(i-1,j-1,s1,s2,dp));
        }
        else
        {
            not_match = max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
        }

        return dp[i][j]=max(match, not_match);

    }

    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length();
        int l2=text2.length();

        vector<vector<int>> dp(l1,vector<int>(l2,-1));
        return f(l1-1,l2-1,text1,text2,dp);
        
    }
};