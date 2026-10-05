class Solution {

public:
    bool dfsCycle(int i,vector<int>& vis,vector<int>& path, vector<vector<int>>& adjList)
        {
            if(vis[i]==1)
                return true;
            if(vis[i]==2)
                return false;
            
            vis[i]=1;
            for(int x : adjList[i])
            {
                if(dfsCycle(x,vis,path,adjList))
                    return true;
            }
            vis[i]=2;
            path.push_back(i);
            return false;
        }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        vector<vector<int>> adjList(numCourses);
        vector<int> ans, path;

        for(vector<int> v : prerequisites)
            adjList[v[1]].push_back(v[0]);

        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
                if(dfsCycle(i,vis,path,adjList)) {
                    ans.clear();
                    return ans;
                }
                    
            ans.insert(ans.end(), path.begin(),path.end());
            path.clear();
        }
        reverse(ans.begin(),ans.end());
        return ans;   
    }
};


