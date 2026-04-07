class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();long long int p=1; int c=0;
        for(int i=0;i<n;i++)
        {
            p=1;
            for(int j=i;j<n;j++)
            {
                p=p*nums[j];
                if(p<k)
                    c++;
                else
                    break;
            }
        }
        return c;
    }
};