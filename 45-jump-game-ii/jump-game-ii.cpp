class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, curEnd = 0, farthest = 0;
        for (int i = 0; i + 1 < (int)nums.size(); ++i) {
            farthest = max(farthest, i + nums[i]);
            if (i == curEnd) {                    // end of the current jump's reach
                ++jumps;
                curEnd = farthest;
            }
        }
        return jumps;
    }
};
