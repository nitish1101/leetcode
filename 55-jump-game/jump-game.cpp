#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 55: Jump Game
// Greedy: track the farthest index reachable so far. If the current index is
// beyond it, we are stuck.
// Time: O(n), Space: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0, n = (int)nums.size();
        for (int i = 0; i < n; i++) {
            if (i > farthest) return false;
            farthest = max(farthest, i + nums[i]);
            if (farthest >= n - 1) return true;
        }
        return true;
    }
};
