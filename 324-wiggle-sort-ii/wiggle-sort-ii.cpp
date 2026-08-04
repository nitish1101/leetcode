class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=(n%2==0) ? (n/2)-1 : n/2; 
        vector<int> ans;

        int i=mid;
        int j=n-1;

        while(i>=0 && j>mid)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i--;
            j--;
        }
        if(n!=0 && i==0)
            ans.push_back(nums[i]);

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






        