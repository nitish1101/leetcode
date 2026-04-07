import java.util.*;
class Solution {
    int f(int i,int n,Vector<Integer> dp)
    {
        if(i==n-1)
            return 1;
        if(i==n-2)
            return 2;
        if(dp.get(i)!=-1)
            return dp.get(i);
        dp.set(i,f(i+1,n,dp)+f(i+2,n,dp));
        return dp.get(i);
    }
    public int climbStairs(int n) {
        /**
        n=3
        1 1 1
         1 2
         2 1

        

         */
         Vector<Integer> dp=new Vector<>(n+1);
         for(int i=0;i<n;i++)
            dp.add(i,-1);

         return f(0,n,dp);
    }
}