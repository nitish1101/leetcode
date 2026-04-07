class Solution {
public:

    int dfs(int i,int d,int k, vector<pair<int,int>> adj[],vector<vector<int>>& vis)
    {
        if(i==d)
            return 0;
        if(k<0)
            return INT_MAX;
        if(vis[i][k]!=-1)
            return vis[i][k];

        int mini=INT_MAX;
        for(int j=0;j<adj[i].size();j++) {
            int res=dfs(adj[i][j].first,d,k-1,adj,vis);
            if(res!=INT_MAX)
                mini= min(mini,res+adj[i][j].second);
        }
        return vis[i][k]=mini;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int>> adj[n];
        vector<vector<int>> vis(n,vector<int>(n,-1));
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }
        
        int ans=dfs(src,dst,k,adj,vis);
        return ans!=INT_MAX ? ans:-1;
    }
};