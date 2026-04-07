class Solution {
public:
    bool isValid(int i, int j, int n, int m)
    {
        return i>=0 && j>=0 && i<n && j<m;
    }

    int f(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>& vis, int n, int m )
    {
        
        if(vis[i][j]!=0)
            return vis[i][j];
        
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        int tmp=1;
        for(int k=0;k<4;k++)
        {
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(isValid(nr,nc,n,m)  && matrix[nr][nc] > matrix[i][j])
            {
                tmp=max(tmp,1+f(nr,nc,matrix,vis,n,m));
            }
        }
        return vis[i][j]=tmp;

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j])
                {
                    int res=f(i,j,matrix,vis,n,m);
                    ans=max(ans,res);
                }
            }
        }

   

        return ans;
    }
};