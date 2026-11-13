#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Adjacent endpoints cannot both be chosen. Exclude each in turn.
        auto robLine = [&](int begin, int end) {
            int previous = 0, twoBack = 0;
            for (int i = begin; i < end; ++i) {
                int best = max(previous, twoBack + nums[i]);
                twoBack = previous;
                previous = best;
            }
            return previous;
        };
        return max(robLine(0, n - 1), robLine(1, n));
    }
};
