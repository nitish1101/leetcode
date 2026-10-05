class Solution {
public:

    bool dfsCycle(int i,vector<int>& vis, vector<vector<int>>& adjList)
    {
        if(vis[i]==1)
            return true;
        if(vis[i]==2)
            return false;
        
        vis[i]=1;
        for(int x : adjList[i])
        {
            if(dfsCycle(x,vis,adjList))
                return true;
        }
        vis[i]=2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> vis(numCourses,0);
        vector<vector<int>> adjList(numCourses);
        for(vector<int> v : prerequisites)
            adjList[v[1]].push_back(v[0]);

        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
                if(dfsCycle(i,vis,adjList)==true)
                    return false;
        }
        return true;
    }
};


/**a

if cyc => false





*/