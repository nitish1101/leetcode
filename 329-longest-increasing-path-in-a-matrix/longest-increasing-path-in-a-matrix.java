import java.util.*;
import static java.lang.Math.max;
class Solution {


    static boolean isValid(int i, int j, int m, int n) {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }

    // f(i,j) represents LISeq from (i,j)
    static int f(int i, int j, int[][] matrix,
          int[][] dp) {

        
        if(dp[i][j]!=-1)
            return dp[i][j];

        int m=matrix.length;
        int n=matrix[0].length;
        int up=0,left=0,right=0,bottom=0;
        
        if(isValid(i-1,j,m,n) && matrix[i-1][j]>matrix[i][j])
            up=f(i-1,j,matrix,dp);
        if(isValid(i,j+1,m,n) && matrix[i][j+1]>matrix[i][j] )
            right=f(i,j+1,matrix,dp);
        if(isValid(i+1,j,m,n) && matrix[i+1][j]>matrix[i][j])
            bottom=f(i+1,j,matrix,dp);
        if(isValid(i,j-1,m,n) && matrix[i][j-1]>matrix[i][j] )
            left=f(i,j-1,matrix,dp);

        return dp[i][j]=1+max(up,max(left,max(bottom,right)));
    }


    public int longestIncreasingPath(int[][] matrix) {

        int m=matrix.length;
        int n=matrix[0].length;
        int[][] dp=new int[m][n];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
        int ans=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==-1)
                    ans=max(ans,f(i,j,matrix,dp));
            }
        return ans;
    }
}