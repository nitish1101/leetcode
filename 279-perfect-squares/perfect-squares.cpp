#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int total = 1; total <= n; ++total) {
            // Choose the final square and solve the remaining smaller total.
            for (int root = 1; root <= total / root; ++root)
                dp[total] = min(dp[total], 1 + dp[total - root * root]);
        }
        return dp[n];
    }
};
