class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = static_cast<int>(intervals.size());
        int start = newInterval[0];
        int end = newInterval[1];

        while (i < n && intervals[i][1] < start) {
            result.push_back(intervals[i++]);
        }
        // Equal endpoints overlap because intervals are closed.
        while (i < n && intervals[i][0] <= end) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            ++i;
        }
        result.push_back({start, end});
        while (i < n) {
            result.push_back(intervals[i++]);
        }

        return result;
    }
};
