class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        reverse(nums.begin(),nums.end());
        int e=nums[i];
        if(n==1)
            return true;
        for(int i=0;i<n;)
        {
            int e=nums[i];
            int j=i;
            while(j<(i+k))
            {
                if(j==n || nums[j] < e)
                    return false;
                nums[j]-=e;
                j++;
            }
            while(i<n && nums[i]==0)
                i++; 
            
            cout << i << endl;
        }
        return true;
        
    }
};