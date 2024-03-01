class Solution {
    vector<vector<int>> ans;
public:
    void f(int i, int target, int k, vector<int>& tmp)
    {
        if(target < 0)
            return;
        if(k==0)
        {
            if(target==0)
                ans.push_back(tmp);
            return;
        }
        for(int x=i;x<=9;x++){
            tmp.push_back(x);
            f(x+1,target-x,k-1,tmp);
            tmp.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;  
        f(1,n,k,tmp);
        return ans;
    }
};