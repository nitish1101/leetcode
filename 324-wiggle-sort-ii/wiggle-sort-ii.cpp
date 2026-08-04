class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid= (n-1)/2;
        vector<int> ans;

        int i=mid;
        int j=n-1;

        for(int i=mid,j=n-1; i>=0 || j>mid; i--,j--)
        {
            if(i>=0)
                ans.push_back(nums[i]);
            if(j>mid)
                ans.push_back(nums[j]);
            
        }
        nums=ans;
    }
};  
    
/**
4,5 m=0

3,4,5,6,7. m=1, i=1, j=1
5,7,4,6,

5,6,4

4 , m=0;

4,5,5,6  mid=1

5,6,4,5

6,5,5,4
5,6,4,5

4,6

*/






        