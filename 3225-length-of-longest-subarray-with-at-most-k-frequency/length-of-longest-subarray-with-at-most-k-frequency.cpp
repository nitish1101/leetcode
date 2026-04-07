class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int i=0,j=0;
        int maxi=INT_MIN;
        while(j<n)
        {
            mp[nums[j]]++;
            if(mp[nums[j]] > k)
            {
                maxi=max(maxi,j-i);
                while(mp[nums[j]]>k)
                {
                    mp[nums[i]]--;
                    i++;
                }
            }
            j++;
        }
        maxi=max(maxi,j-i);
        return maxi;
        
        
    }
};