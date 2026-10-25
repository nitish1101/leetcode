class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];                           // single digit 1-9
            if (i >= 2 && s[i - 2] == '1') dp[i] += dp[i - 2];                 // pair 10-19
            else if (i >= 2 && s[i - 2] == '2' && s[i - 1] <= '6') dp[i] += dp[i - 2];  // pair 20-26
        }
        return dp[n];
    }
};
