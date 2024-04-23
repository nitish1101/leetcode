class Solution {
public:

    int f(string s, int i,int j,vector<vector<int>>& dp)
    {
        if(i==j)
            return 1;
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int r=0;
        if(s[i]==s[j])
            dp[i][j]=2+f(s,i+1,j-1,dp);
        else
            dp[i][j]=max(f(s,i+1,j,dp),f(s,i,j-1,dp));
        return dp[i][j];
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};