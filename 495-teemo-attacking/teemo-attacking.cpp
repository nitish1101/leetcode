class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
      /**
        1,2
        4,5

        1,2
        2,3
        1,3
        */
       vector<int> ts(timeSeries);
       int n=ts.size();
       int d=duration;
       int ans=d;
       int i=1;
       while(i<n)
       {
        if(ts[i] >= ts[i-1]+d)
            ans+=d;
        else
            ans+=ts[i]-ts[i-1];

        i++;
       }
       return ans;

    }
};