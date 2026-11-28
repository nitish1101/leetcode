#include <vector>

// 88. Merge Sorted Array
// Merge two integer arrays nums1 and nums2, sorted in non-decreasing order,
// into nums1 in-place. nums1 has length m + n, where the first m elements are
// the values to merge and the last n are zero placeholders.
//
// Fill nums1 from the back with the larger of the two current tails, so no
// unmerged value in nums1 is ever overwritten.
// Time: O(m + n), Space: O(1).
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
    }
};
