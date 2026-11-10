class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-heap of the k closest points so far, keyed by squared distance.
        priority_queue<pair<long,int>> heap;
        for (int i = 0; i < (int)points.size(); ++i) {
            long d = (long)points[i][0] * points[i][0]
                   + (long)points[i][1] * points[i][1];
            heap.push({d, i});
            if ((int)heap.size() > k) heap.pop();   // drop the farthest
        }
        vector<vector<int>> result;
        while (!heap.empty()) {
            result.push_back(points[heap.top().second]);
            heap.pop();
        }
        return result;
    }
};
