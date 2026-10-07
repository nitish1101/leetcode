#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> candidates;
        vector<int> result;
        result.reserve(nums.size() - k + 1);

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            // Discard indices outside the current window.
            while (!candidates.empty() && candidates.front() <= i - k) {
                candidates.pop_front();
            }
            // Keep values decreasing: older, smaller values cannot win.
            while (!candidates.empty() && nums[candidates.back()] <= nums[i]) {
                candidates.pop_back();
            }
            candidates.push_back(i);
            if (i >= k - 1) {
                result.push_back(nums[candidates.front()]);
            }
        }
        return result;
    }
};
// Time: O(n). Auxiliary space: O(k), excluding the output.
