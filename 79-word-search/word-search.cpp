class Solution {
public:
    bool  f(int i,int j,int k,int m,int n, vector<vector<char>>& grid, string word, bool vis[][6])
    {
        
        if(k==word.length() || (k==word.length()-1 && word[k]==grid[i][j]))
           return true; 
        
        if(word[k] == grid[i][j])
         {  
            vis[i][j]=true; 
            if(j+1 < n && !vis[i][j+1] && f(i,j+1,k+1,m,n,grid,word,vis))
                return true;
            if(j-1 >=0 && !vis[i][j-1] && f(i,j-1,k+1,m,n,grid,word,vis))
                return true;
            if(i+1 < m && !vis[i+1][j] && f(i+1,j,k+1,m,n,grid,word,vis))
                return true;
            if(i-1 >= 0 && !vis[i-1][j] && f(i-1,j,k+1,m,n,grid,word,vis))
                return  true;
         }
         vis[i][j]=false;
        return false;
           
        
        

    }
    bool exist(vector<vector<char>>& board, string word) {
         int m=board.size();
         int n=board[0].size();
         int k=0;
         bool vis[6][6];
         for(int i=0;i<m;i++)
         {
           for(int j=0;j<n;j++)
           {

               if(f(i,j,k,m,n,board,word,vis))
                    return true;
           }
         }
         return false;
        
    }
};