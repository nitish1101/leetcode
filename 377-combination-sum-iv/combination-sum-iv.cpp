class Solution {
public:
    int rec(int t, vector<int>& nums, vector<int>& dp) {
        if (t < 0)
            return 0;
        if (t == 0)
            return 1;
        if(dp[t]!=-1)
            return dp[t];
        int c = 0;
        for (int x : nums)
            c = c + rec(t - x, nums, dp);
        return dp[t]=c;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return rec(target, nums, dp);
    }
};

/**
nums[], t, k(xxxx),

1,2,3. --- 4

1,1,1,1 xx
1,1,1,1 (0)=1 +1,1,1,2 ()
1,1,1,2 xxxx
1,1,2
1,1,3 xxxx
1,2,2 xxx
1,3,
2,2
i=4 xxxx

f(i,t,c,nums)

if(i == n)
    return;
if(t==0)
    c++;
    return;
if(t<0)
    return;

//pick i
rec(i,t-nums[i],c,nums)

//np i
rec(i+1,t,c,nums);











*/