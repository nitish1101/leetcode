class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();
        int islands = 0;
        vector<pair<int, int>> pending;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] != '1') continue;
                ++islands;
                grid[row][col] = '0';
                pending.push_back({row, col});

                while (!pending.empty()) {
                    auto [r, c] = pending.back();
                    pending.pop_back();
                    if (r > 0 && grid[r - 1][c] == '1') {
                        grid[r - 1][c] = '0';
                        pending.push_back({r - 1, c});
                    }
                    if (r + 1 < rows && grid[r + 1][c] == '1') {
                        grid[r + 1][c] = '0';
                        pending.push_back({r + 1, c});
                    }
                    if (c > 0 && grid[r][c - 1] == '1') {
                        grid[r][c - 1] = '0';
                        pending.push_back({r, c - 1});
                    }
                    if (c + 1 < cols && grid[r][c + 1] == '1') {
                        grid[r][c + 1] = '0';
                        pending.push_back({r, c + 1});
                    }
                }
            }
        }
        return islands;
    }
};
