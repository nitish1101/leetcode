class Solution {
public:
    int maxi(vector<int>& v)
    {
        int maxii=INT_MIN;
        for(int i : v)
        {
            maxii=max(i,maxii);
        }
        return maxii;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxii=INT_MIN;
        for(int i : piles)
        {
            maxii=max(i,maxii);
        }

        int high=maxii;
        int low=1;
        int mid=0;
        while(low<high)
        {
            mid=low+ (high-low)/2;
            int hours=0;
            for(int i : piles)
            {
                hours += (i + mid - 1) / mid;
            }
            if(hours > h)
            {
                low=mid+1;
            }
           else
            {
                high=mid;
            }
        }
        return low;  
    }
};


/**
lb = total/h -> 1

ub = max(piles[i]) ->  10^9

piles[i]%mid = x 
if(x)=> x+1;
else
x <= h-1








*/