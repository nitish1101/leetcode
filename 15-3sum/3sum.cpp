class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n>=3 && nums[0]==0 && nums[n-1]==0)
            return {{0,0,0}};
        set<vector<int>> ans;
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
            mp[nums[i]]=i;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                auto it=mp.find(-(nums[i]+nums[j]));
                if(it!=mp.end() && it->second!=i && it->second !=j)
                {
                    vector<int> tmp={nums[i],nums[j],it->first};
                    sort(tmp.begin(),tmp.end());
                    ans.insert(tmp);
                }
            }
        }
        vector<vector<int>> v(ans.begin(),ans.end());
        return v;
    }
};