class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)              // transpose
            for (int j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
        for (auto& row : matrix)                  // mirror each row
            reverse(row.begin(), row.end());
    }
};
