class Solution {
    vector<int> v;
public:
    bool dfs(int i,  unordered_map<int,vector<int>>& mp,bool vis[],bool mainVis[])
    {
        vis[i]=1;
        mainVis[i]=1;
        for(auto e: mp[i])
        {
            if(vis[e]) {
                cout<<"Holla-"<<i<<e<<endl;
                return false;
            }
            if(!mainVis[e])
                if(!dfs(e,mp,vis,mainVis))
                    return false;
        }
        vis[i]=false;
        v.push_back(i);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        int n=numCourses;
        bool vis[2001]={false};
        bool mainVis[2001]={false};
        for(auto i : prerequisites)
        {
            mp[i[0]].push_back(i[1]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!mainVis[i])
                if(!dfs(i,mp,vis,mainVis))
                    return {};
        }
        return v;
        
    }
};