class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outdegree(n+1,0);
        vector<int> indegree(n+1,0);
        outdegree[0]=-1;
        indegree[0]=-1;
        for(auto p : trust) {
            outdegree[p[0]]++;
            indegree[p[1]]++;
        }
        for(int i=0;i<=n;i++)
            if(outdegree[i]==0 && indegree[i]==n-1)
                return i;
        return -1;
    }
};