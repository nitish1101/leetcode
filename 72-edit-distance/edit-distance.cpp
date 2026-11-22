#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = (int)word1.size(), n = (int)word2.size();
        // dp[j] = edit distance between word1[:i] and word2[:j], rolling rows.
        vector<int> dp(n + 1);
        for (int j = 0; j <= n; ++j) dp[j] = j;  // word1 empty: insert all of word2[:j]
        for (int i = 1; i <= m; ++i) {
            int prev = dp[0];      // dp[i-1][j-1] before it is overwritten
            dp[0] = i;             // word2 empty: delete all of word1[:i]
            for (int j = 1; j <= n; ++j) {
                int cur = dp[j];   // dp[i-1][j]: delete word1[i-1]
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev;
                } else {
                    // replace (prev), delete (cur), insert (dp[j-1])
                    dp[j] = 1 + min({prev, cur, dp[j - 1]});
                }
                prev = cur;
            }
        }
        return dp[n];
    }
};
