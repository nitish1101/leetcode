//0,0,1
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0; int x=-1; int maxi=0;
        while(j<n)
        {
            
            if(nums[j]==0) {
                if(x>=0)
                {
                    maxi=max(maxi,j-i-1);
                    i=x+1;
                }
                x=j;
            } 
            j++;    
        }
        return maxi=max(maxi,j-i-1);
    }
};

/**
0
0,1,1,1,0,1,1,0,1
. . . .1

1,0,1,1,0,1,1,1,0
    i...........j
x=1;
maxi=j-i-1;
*/

