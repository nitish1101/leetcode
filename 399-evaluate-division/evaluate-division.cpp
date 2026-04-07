class Solution {
    vector<double> ans;
public:
    bool findPath(string s, string d, unordered_map<string, vector<pair<string, double>>>& mp, unordered_set<string>& vis, double res)
    {
        vis.insert(s);
        if(s==d){
            ans.push_back(res);
            vis.erase(s);
            return true;
        }
        
        for(auto e: mp[s])
        {
            if(vis.find(e.first)==vis.end())
            {
                if(findPath(e.first,d,mp,vis,res*e.second)){
                     vis.erase(s);
                    return true;  
                } 
            }
        }
        vis.erase(s);
        return false;
    }

    bool isValidVariable(string s,unordered_map<string, vector<pair<string, double>>>& mp)
    {
        
        if(mp.find(s)==mp.end())
            return false;
        return true;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
       unordered_map<string, vector<pair<string, double>>> mp;
       for(int i=0;i<equations.size();i++)
       {
           mp[equations[i][0]].push_back({equations[i][1],values[i]});
           mp[equations[i][1]].push_back({equations[i][0],(1/values[i])}); 
       }
       for(auto e : mp)
       {
           for(auto v: e.second)
           {
               cout<<v.first<<" "<<v.second<<",";
           }
           cout<<endl;
       }
      
       unordered_set<string> vis;
       for(auto v: queries)
       {
           if(!isValidVariable(v[0],mp) || !isValidVariable(v[1],mp)){
                ans.push_back(-1);
                continue;
           }
           if(!findPath(v[0],v[1],mp,vis,1))
                ans.push_back(-1);
       }
       return ans;
    }
};

