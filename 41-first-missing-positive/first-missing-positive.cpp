class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            if(nums[i] <= 0)
                nums[i]=INT_MAX;
        sort(nums.begin(),nums.end());
        unordered_set<int> mp(nums.begin(),nums.end());
        int c=1;
        while(c<=n)
        {
            if(mp.find(c)==mp.end())
                return c;
            c++;
        }
       
        return c;
    }
};