class Solution {
public:
     vector<vector<int>> ans;
    void f(int n,int k,int idx, unordered_set<int>& vis, vector<int>& tmp)
    {
        if(vis.size() == k)
        {
            ans.push_back(tmp);
            return;   
        }
        for(int i=idx+1;i<=n;i++)
        {
            if(vis.find(i)==vis.end())
            {
                tmp.push_back(i);
                vis.insert(i);
                f(n,k,i,vis,tmp);
                vis.erase(i);
                tmp.pop_back();
            }
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        unordered_set<int> vis;
        vector<int> tmp;
        f(n,k,0,vis,tmp);
        return ans;
        
    }
};