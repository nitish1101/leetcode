//This is KADANE , works for atleast 1 +ve ele in array
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//        int len=nums.size();
//         int sum=0;
//         int ans=INT_MIN;
//         for(int i=0;i<len;i++)
//         {
//             if((sum+nums[i])>=0)
//             {
//                 sum+=nums[i];
//                 ans=max(ans,sum);
//             }
//             else
//             {
//                 sum=0;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        for(auto i: nums)
        {
            if(i<=0)
                mini=min(mini,abs(i));
        }
        cout<<mini<<endl;
        int i=0,j=0;
        int s=0;int ms=-1*mini;
        while(j<n)
        {
            cout<<s<<endl;
            s=s+nums[j];
            if(s<=0)
            {
                j++;
                i=j;
                s=0;
                continue;
            }
            ms=max(ms,s);
            j++;
        }
        return ms;
    }
};
/**

   int len=nums.size();
        int sum=0;
        int mss=nums[0]; //max sum difference
        int mini=0; //lowest sum
        for(int i=0;i<len;i++)
        {
            sum+=nums[i];
            mss=max(mss,sum-mini);
            mini=min(sum,mini);
        }
        return mss;

*/