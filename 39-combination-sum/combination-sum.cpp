class Solution {
public:
     set<vector<int>> ans;
     vector<vector<int>> res;
     void f(vector<int>& nums,int target, vector<int>& tmp)
    {
        if(target<0)
            return;
        if(target==0)
        {
            vector<int> v(tmp.begin(),tmp.end());
            sort(v.begin(),v.end());
            if(ans.find(v)==ans.end()){
                ans.insert(v);
                res.push_back(v);
            }
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
                tmp.push_back(nums[i]);
               
                f(nums,target-nums[i],tmp);
                
                tmp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        f(candidates,target,tmp);
        return res;
    }
};