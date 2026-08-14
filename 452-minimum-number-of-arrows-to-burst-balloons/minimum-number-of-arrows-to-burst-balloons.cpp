class Solution {

        static bool cmp(vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        }

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), cmp);

        stack<pair<int, int>> s;
        s.push({points[0][0], points[0][1]});

        int j = 1;
        while (!s.empty() && j < n) {
            pair<int, int> p = s.top();
            if (points[j][0] <= p.second) {
                s.pop();
                s.push({max(p.first, points[j][0]), min(p.second, points[j][1])});
            }
            else
                s.push({points[j][0], points[j][1]});
            j++;
        }
        return s.size();
    }
};

