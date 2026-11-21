#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Binary search the partition of the smaller array.
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = (int)nums1.size(), n = (int)nums2.size();
        int half = (m + n + 1) / 2;  // left side size (gets the extra element when odd)
        int lo = 0, hi = m;
        while (lo <= hi) {
            int i = lo + (hi - lo) / 2;  // elements taken from nums1
            int j = half - i;            // elements taken from nums2
            int l1 = (i > 0) ? nums1[i - 1] : INT_MIN;
            int r1 = (i < m) ? nums1[i] : INT_MAX;
            int l2 = (j > 0) ? nums2[j - 1] : INT_MIN;
            int r2 = (j < n) ? nums2[j] : INT_MAX;
            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2 == 1) return (double)max(l1, l2);
                return (max(l1, l2) + (long long)min(r1, r2)) / 2.0;
            }
            if (l1 > r2) hi = i - 1;
            else lo = i + 1;
        }
        return 0.0;  // unreachable: inputs are sorted
    }
};
