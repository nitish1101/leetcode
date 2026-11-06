class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        function<void(int)> dfs = [&](int i) {
            if (i == (int)nums.size()) { result.push_back(cur); return; }
            dfs(i + 1);                 // exclude nums[i]
            cur.push_back(nums[i]);     // include nums[i]
            dfs(i + 1);
            cur.pop_back();
        };
        dfs(0);
        return result;
    }
};
