class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> indegree(numCourses,0);
        vector<vector<int>> adjList(numCourses);
        for(vector<int> v : prerequisites)
        {
            indegree[v[0]]++;
            adjList[v[1]].push_back(v[0]);
        }
        queue<int> startNodes;
        for(int i=0;i< numCourses ;i++)
        {
            if(indegree[i]==0)
                startNodes.push(i);
        }

        while(!startNodes.empty())
        {
            int x=startNodes.front();
            startNodes.pop();
            for(int i : adjList[x])
            {
                indegree[i]--;
                if(indegree[i]==0)
                    startNodes.push(i);
            }
        }
        
        for(int x : indegree)
        {
            if(x==0)
                numCourses--;
        }
        if(numCourses)
            return false;
        return true;
    }
};


/**a

if cyc => false





*/