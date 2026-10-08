#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) {
            return false;
        }
        const int target = total / 2;
        vector<bool> reachable(target + 1, false);
        reachable[0] = true;

        for (int value : nums) {
            // Descending sums ensure each element is used at most once.
            for (int sum = target; sum >= value; --sum) {
                reachable[sum] = reachable[sum] || reachable[sum - value];
            }
            if (reachable[target]) {
                return true;
            }
        }
        return reachable[target];
    }
};
// Time: O(n * target). Auxiliary space: O(target).
