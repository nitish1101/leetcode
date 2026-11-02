class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n)), atl(m, vector<bool>(n));
        static const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // Flood inland from an ocean-border cell through non-decreasing heights.
        auto mark = [&](int si, int sj, vector<vector<bool>>& vis) {
            vector<pair<int,int>> st{{si, sj}};
            vis[si][sj] = true;
            while (!st.empty()) {
                auto [i, j] = st.back(); st.pop_back();
                for (auto& [di, dj] : d) {
                    int ni = i + di, nj = j + dj;
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (vis[ni][nj] || heights[ni][nj] < heights[i][j]) continue;
                    vis[ni][nj] = true;
                    st.push_back({ni, nj});
                }
            }
        };
        for (int i = 0; i < m; ++i) { mark(i, 0, pac); mark(i, n - 1, atl); }
        for (int j = 0; j < n; ++j) { mark(0, j, pac); mark(m - 1, j, atl); }
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (pac[i][j] && atl[i][j]) result.push_back({i, j});
        return result;
    }
};
