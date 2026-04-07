class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int k=0;
        for(auto e : nums)
        {
            if(e!=0)
                nums[k++]=e;
        }
        while(k<n)
        {
            nums[k++]=0;
        }

        
    }
};