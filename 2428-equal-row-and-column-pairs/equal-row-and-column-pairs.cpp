class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> cgrid(grid);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                swap(grid[i][j], grid[j][i]);

        int c=0;
        for (int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(grid[i]==cgrid[j])
                    c++;
        return c;
    }
};


/**
321 176 277
312 277 167

*/