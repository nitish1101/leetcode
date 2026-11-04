class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        size_t maxLen = 0;
        for (auto& w : wordDict) maxLen = max(maxLen, w.size());
        int n = s.size();
        vector<bool> dp(n + 1, false);   // dp[i]: s[0..i) is segmentable
        dp[0] = true;
        for (int i = 1; i <= n; ++i)
            for (int j = i - 1; j >= 0 && i - j <= (int)maxLen; --j)
                if (dp[j] && dict.count(s.substr(j, i - j))) { dp[i] = true; break; }
        return dp[n];
    }
};
