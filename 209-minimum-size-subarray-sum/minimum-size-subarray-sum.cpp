class Solution {
public:
   
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=-1,j=0;
        int s=0; int mini=INT_MAX;
        while(j<n)
        {
            s=s+nums[j];
            while(s>=target && i<j)
            {
                mini=min(mini,j-i);
                i++;
                s=s-nums[i];
            }
            j++;
        }
        return (mini==INT_MAX ? 0:mini);

    }
};