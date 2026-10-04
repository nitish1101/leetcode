// class Solution {
// public:

//     bool isValid(int i, int j, int r, int c, vector<vector<int>>& grid)
//     {
//         if(i < 0 || j < 0 || i >= r || j >= c || grid[i][j]!=1 )
//             return false;
//         return true;
//     }
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n= grid.size();
//         int m=grid[0].size();

//         vector<int> dx={0,+1,0,-1};
//         vector<int> dy={+1,0,-1,0};
//         queue<pair<int,int>> q;
        
//        for(int i=0;i<n;i++) {
//             for(int j=0;j<m;j++)
//             {
//                 if(grid[i][j]==2)
//                     q.push({i,j});
//             }
//        }

//        int ans=-1;
//        while(!q.empty())
//        {
//             int s=q.size();
//             for(int k=0;k<s;k++)
//             {
//                 auto[x,y] = q.front();
//                 q.pop();

//                 for(int i=0;i<4;i++)
//                 {
//                     int nr = x + dx[i];
//                     int nc = y + dy[i];
//                     if(isValid(nr,nc,n,m,grid)==true)
//                     {
//                         grid[nr][nc]=2; // rot it
//                         q.push({nr,nc});
//                     }
//                 } 
//             }
//             ans++;  
//        }

//         // any fresh orange left
//        for(int i=0;i<n;i++) {
//             for(int j=0;j<m;j++)
//             {
//                 if(grid[i][j]==1)
//                     return -1;
//             }
//        }

//        int flag=0;
//        for(int i=0;i<n;i++) {
//             for(int j=0;j<m;j++)
//             {
//                 if(grid[i][j]==0)
//                     continue;
//                 else {
//                     flag=1;
//                     break;
//                 }
                    
//             }
//        }

//        if(!flag)
//         return 0;

//        return ans;
//     }
// };

// /**

// push all rotten oranges in to a queue
// pop all of them out
// rot the neighbours ans push them back

// inc ans by 1
// do this until queue is empty

// if any remias 1, return -1

// */


class Solution {
public:

    bool isValid(int i, int j, int r, int c, vector<vector<int>>& grid) {
        return i >= 0 && j >= 0 &&
               i < r && j < c &&
               grid[i][j] == 1;
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        queue<pair<int, int>> q;

        int fresh = 0;

        // Initialize BFS + count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        while (!q.empty() && fresh > 0) {

            int size = q.size();

            while (size--) {

                auto [x, y] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {

                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (isValid(nx, ny, n, m, grid)) {

                        grid[nx][ny] = 2;
                        fresh--;

                        q.push({nx, ny});
                    }
                }
            }

            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};