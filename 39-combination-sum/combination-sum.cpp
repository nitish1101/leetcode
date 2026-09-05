class Solution {
public:
    void rec(int i, int t, vector<int>& cd, vector<int>& comb, vector<vector<int>>& ans)
    {
        if(t==0)
        {
            ans.push_back(comb);
            return;
        }
        if(t<0)
            return;

        for(int x=i;x<cd.size();x++)
        {
            comb.push_back(cd[x]);
            rec(x,t-cd[x],cd,comb,ans);
            comb.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> ans;
        rec(0,target,candidates, comb,ans);
        return ans;
        
    }
};



/**
2,3,6,7,    7

[2.],5,     [3,],4.     [6],
    [2.2],3 -> [2.2.2],1 -> xx
    [2.3],2 -> [2.3.2],0 -> return [2.3.2] xx  
    xx




*/