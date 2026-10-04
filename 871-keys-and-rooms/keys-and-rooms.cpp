class Solution {
    

public:
    void dfs(int i,  vector<vector<int>>& rooms,  vector<bool>& vis)
    {
        vis[i]=true;
        for(int x : rooms[i])
        {
            if(!vis[x])
                dfs(x,rooms,vis);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        dfs(0,rooms,vis);

        for(bool x : vis)
            if(x==false)
                return false;
        
        return true;
    }
};




/***
    0       1   2   3
[[1,3],[3,0,1],[2],[0]]

0->1
0->3
1->3
1->0
1->1
2->2
3->0




*/

