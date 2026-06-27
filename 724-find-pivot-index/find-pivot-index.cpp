class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> pf(n,0);
        pf[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pf[i]=pf[i-1]+nums[i];
        }
        for(int i=0;i<n;i++)
        {
            int ls=0;
            if(i==0)
                ls=0;
            else
                ls=pf[i-1];
            int rs=pf[n-1]-pf[i];
            if(ls==rs) {
                return i;
            }
        }
        return -1;
    }
};




