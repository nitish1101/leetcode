class Solution {
public:
    int f(int i, vector<int>& arr, int k,int n, vector<int>& dp)
    {
        if(i==n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];

        int sum=0;
        int ans=INT_MIN;
        int maxi=INT_MIN;
        int len=0;

        for(int j=i;j<min(n,i+k);j++)
        {
            len++;
            maxi=max(arr[j],maxi);
            sum=(len*maxi) + f(j+1,arr,k,n,dp);
            ans=max(ans,sum);
        }
        return dp[i]=ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        return f(0,arr,k,n,dp);  
    }
};