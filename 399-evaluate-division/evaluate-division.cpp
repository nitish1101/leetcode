class Solution {
public:
    double dfs(string s, string d,
               unordered_map<string, vector<pair<string, double>>>& adj,
               unordered_set<string>& vis) {

        if (s == d)
            return 1.0;

        vis.insert(s);

        for (auto x : adj[s]) {
            string next = x.first;
            double cost = x.second;

            if (!vis.count(next)) {
                double res = dfs(next, d, adj, vis);

                if (res != -1.0)
                    return cost * res;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string, double>>> adj;

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];

            adj[a].push_back({b, values[i]});
            adj[b].push_back({a, 1.0 / values[i]});
        }

        vector<double> ans;

        for (auto& q : queries) {
            string src = q[0];
            string dst = q[1];

            if (!adj.count(src) || !adj.count(dst)) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> vis;
            ans.push_back(dfs(src, dst, adj, vis));
        }

        return ans;
    }
};