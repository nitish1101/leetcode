#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Cancel unequal pairs. The guaranteed majority survives.
        int candidate = 0, balance = 0;
        for (int value : nums) {
            if (balance == 0) candidate = value;
            balance += (value == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
