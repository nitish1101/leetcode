class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<vector<pair<int, int>>> adjList(n);

        for (auto x : flights)
            adjList[x[0]].push_back({x[1], x[2]});

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        dist[src][0] = 0;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();

            int cd = t[0];
            int node = t[1];
            int steps = t[2];

            if (steps == k + 1)
                continue;

            if (cd != dist[node][steps])
                continue;

            for (auto x : adjList[node]) {
                int next = x.first;
                int newCost = cd + x.second;
                int newSteps = steps + 1;

                if (newCost < dist[next][newSteps]) {
                    dist[next][newSteps] = newCost;
                    pq.push({newCost, next, newSteps});
                }
            }
        }

        int ans = INT_MAX;

        for (int steps = 0; steps <= k + 1; steps++)
            ans = min(ans, dist[dst][steps]);

        return ans == INT_MAX ? -1 : ans;
    }
};