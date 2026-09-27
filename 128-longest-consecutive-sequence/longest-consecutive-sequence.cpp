class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        int best = 0;

        for (int value : values) {
            if (value != INT_MIN && values.count(value - 1)) continue;

            int length = 1;
            int current = value;
            while (current != INT_MAX && values.count(current + 1)) {
                ++current;
                ++length;
            }
            best = max(best, length);
        }
        return best;
    }
};
