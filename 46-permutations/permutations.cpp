class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>& nums, unordered_set<int>& vis, vector<int>& tmp)
    {
        if(vis.size() == nums.size())
        {
            ans.push_back(tmp);
            return;   
        }
        for(int i=0;i<nums.size();i++)
        {
            if(vis.find(nums[i])==vis.end())
            {
                tmp.push_back(nums[i]);
                vis.insert(nums[i]);
                f(nums,vis,tmp);
                vis.erase(nums[i]);
                tmp.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> vis;
        vector<int> tmp;
        f(nums,vis,tmp);
        return ans;
        
    }
};