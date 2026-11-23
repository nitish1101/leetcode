#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = (int)nums.size();
        int i = n - 2;
        // Find the first index from the right where nums[i] < nums[i+1].
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        if (i >= 0) {
            // Swap with the smallest element to the right larger than nums[i].
            int j = n - 1;
            while (nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        // The suffix is descending; reversing gives the smallest suffix.
        reverse(nums.begin() + i + 1, nums.end());
    }
};
