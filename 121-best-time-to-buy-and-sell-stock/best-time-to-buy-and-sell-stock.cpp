#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// LeetCode 121: Best Time to Buy and Sell Stock
// One pass: track the lowest price seen so far and the best profit
// from selling at the current price.
// Time: O(n), Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = INT_MAX, best = 0;
        for (int p : prices) {
            lowest = min(lowest, p);
            best = max(best, p - lowest);
        }
        return best;
    }
};
