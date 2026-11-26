#include <algorithm>
#include <vector>

// 64. Minimum Path Sum
// Given an m x n grid filled with non-negative numbers, find a path from the
// top-left to the bottom-right corner that minimizes the sum of the numbers
// along the path. You may only move down or right.
//
// DP over a single row: dp[j] is the minimum path sum to reach cell (i, j).
// Time: O(m * n), Space: O(n).
class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<int> dp(n);
        dp[0] = grid[0][0];
        for (int j = 1; j < n; ++j) dp[j] = dp[j - 1] + grid[0][j];
        for (int i = 1; i < m; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j)
                dp[j] = grid[i][j] + std::min(dp[j], dp[j - 1]);
        }
        return dp[n - 1];
    }
};
