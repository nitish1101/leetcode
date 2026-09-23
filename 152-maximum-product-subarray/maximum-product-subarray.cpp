class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pre=1;
        int suff=1;
        int maxi =INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(!pre)
                pre=1;
            if(!suff)
                suff=1;

            pre=pre*nums[i];
            suff=suff*nums[n-i-1];
            maxi=max(maxi,max(pre,suff));

        }
        return maxi;    
    }
};


/**

2,3,-2,4 , 4

2,3,4,2
2,-3,-4,2
2,-3,-3,-3,1
2,-3,-1,-1,3,0,-3,3,-2,8










*/