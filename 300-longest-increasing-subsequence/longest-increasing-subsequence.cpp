#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 300: Longest Increasing Subsequence
// Patience sorting: tails[i] is the smallest possible tail of an increasing
// subsequence of length i + 1. Binary search the slot for each number.
// Time: O(n log n), Space: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) tails.push_back(x);
            else *it = x;
        }
        return (int)tails.size();
    }
};
