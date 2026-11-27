#include <vector>

// 74. Search a 2D Matrix
// Search for a value in an m x n matrix where each row is sorted in
// non-decreasing order and the first integer of each row is greater than the
// last integer of the previous row.
//
// Treat the matrix as one sorted array of m * n cells and binary search it:
// virtual index k maps to cell (k / n, k % n).
// Time: O(log(m * n)), Space: O(1).
class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m * n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int v = matrix[mid / n][mid % n];
            if (v == target) return true;
            if (v < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return false;
    }
};
