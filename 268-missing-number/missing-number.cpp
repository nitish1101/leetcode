#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = static_cast<int>(nums.size());
        // XOR all values with [0, n]; paired values cancel out.
        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            missing ^= i ^ nums[i];
        return missing;
    }
};
