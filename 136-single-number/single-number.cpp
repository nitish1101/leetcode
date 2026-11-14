#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // XOR cancels each equal pair, leaving the unpaired value.
        int result = 0;
        for (int value : nums) result ^= value;
        return result;
    }
};
