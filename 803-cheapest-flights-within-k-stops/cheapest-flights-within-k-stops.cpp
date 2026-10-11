class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        // update distance only if steps less than equal to k+1;
        // pq<vector<int> // dist, node, steps

        vector<vector<pair<int, int>>> adjList(n);

        vector<int> dist(n, INT_MAX);

        // cost,node, steps
        queue<vector<int>> pq;

        for (auto x : flights)
            adjList[x[0]].push_back({x[1], x[2]});

        dist[src] = 0;
        pq.push({0, src, 0});
        while (!pq.empty()) {
            auto t = pq.front();
            int cd = t[0];
            int node = t[1];
            int steps = t[2];
            pq.pop();

            if(steps > k)
                continue;

            for (auto x : adjList[node]) {
                if (cd + x.second < dist[x.first] && steps <= k) {
                    dist[x.first] = cd + x.second;
                    pq.push({dist[x.first], x.first, steps + 1});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};