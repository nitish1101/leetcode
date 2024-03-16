class Solution {
public:
   
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0; int ans=0;
        if(k==0)
        {
            int c=0;
            for(int i=0;i<n;i++)
            {
               if(nums[i]==1)
                    c++;
                else
                {
                    ans=max(ans,c);
                    c=0;
                }
            }
            ans=max(ans,c);
            return ans;
        }
        while(j<n)
        {
            if(nums[j]==0)
            {
                if(k>0)
                {
                    nums[j]=2;
                    k--;
                    j++;
                }
                else
                {
                    ans=max(ans,j-i);
                    while(nums[i]!=2)
                        i++;
                    //out of bounds check
                    nums[i]=0;
                    i++;
                    k++;
                }
            }
            else
                j++; 
        }
        ans=max(ans,j-i);
        return ans;

        
    }
};