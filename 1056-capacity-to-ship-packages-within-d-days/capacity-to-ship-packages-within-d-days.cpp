class Solution {
public:

    /**
        least weight capacity
        max = sum() // 1 day
        min = max(weights) // n days

        10,55

        w

        days


    */

    // 1234
    // 5
    // 6
    // 7
    // 8
    // 9
    // 10

    int f(int cap, vector<int>& weights)
    {
        int n=weights.size();
        int res=1;
        int tmp=0;
        for(int i=0;i<n;i++)
        {
            tmp+=weights[i];
            if(tmp > cap)
            {
                res++;
                tmp=weights[i];
            }
        }
        return res;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int minw=0,maxw=0;
        for(auto w : weights)
        {
            maxw+=w;
            minw=max(minw,w);
        }
        if(days==1)
            return maxw;

        for(int i =minw; i<=maxw; i++)
        {
            int expdaysreq=f(i,weights);
            // cout<<expdaysreq<<endl;
            if(expdaysreq <= days)
            {
                return i;
            }
        }
        return -1;   
    }
};