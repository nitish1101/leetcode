
#define P pair<int, int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // dijkstra n then max dis array
        // bfs with prio queue,
        // dis array
        //  max of that

        vector<int> dis(n + 1, INT_MAX);
        vector<vector<P>> adjList(n + 1);
        priority_queue<P, vector<P>, greater<P>> pq;

        for (auto x : times) {
            adjList[x[0]].push_back({x[1], x[2]});
        }

        dis[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();

            int node = x.second;
            int cd = x.first;

            if (cd > dis[node])
                continue;

            for (auto y : adjList[node]) {
                if (dis[y.first] > cd + y.second) {
                    dis[y.first] = cd + y.second;
                    pq.push({dis[y.first], y.first});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dis[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};