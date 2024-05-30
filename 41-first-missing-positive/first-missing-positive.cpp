class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> mp;
        for(int i=0;i<n;i++)
            if(nums[i] > 0)
                mp.insert(nums[i]);
                
        
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