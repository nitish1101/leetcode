#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Find the first position >= target and the first position > target.
        auto boundary = [&](bool upper) {
            int left = 0, right = static_cast<int>(nums.size());
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] < target || (upper && nums[mid] == target))
                    left = mid + 1;
                else
                    right = mid;
            }
            return left;
        };

        int first = boundary(false);
        if (first == static_cast<int>(nums.size()) || nums[first] != target)
            return {-1, -1};
        return {first, boundary(true) - 1};
    }
};
