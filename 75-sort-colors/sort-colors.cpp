#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // [0, low) are 0s, [low, current) are 1s, (high, n) are 2s.
        int low = 0, current = 0;
        int high = static_cast<int>(nums.size()) - 1;
        while (current <= high) {
            if (nums[current] == 0) {
                swap(nums[low++], nums[current++]);
            } else if (nums[current] == 2) {
                swap(nums[current], nums[high--]);
                // Inspect the incoming value before moving current.
            } else {
                ++current;
            }
        }
    }
};
