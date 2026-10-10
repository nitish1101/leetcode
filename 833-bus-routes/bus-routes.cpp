class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //0 -> 1,2,3  1 -> 3,6,7
        //build graph, busstop => nodes, edges => routes
        //busstops -> buses. build  a map
        //for each stop, find buses from that stop , for each bus, add all the stops that can be vis
        //level at which i reach the destination  is the min buses needed to be baorded

       //n=no of buses
            //busstop vs all the buses from tht stop
        

        unordered_map<int, vector<int>> bsmap;
        unordered_map<int,bool> bsVis;
        vector<bool> bV(routes.size(),false);
       
       for(int i=0;i<routes.size();i++)
       {
            for(int j=0;j<routes[i].size();j++)
            {
                bsmap[routes[i][j]].push_back(i);
                bsVis[routes[i][j]]=false;   
            }
       }
       

       queue<int> q;
       bsVis[source]=true;
       q.push(source);
       int level=0;
       while(!q.empty())
       {
        int s=q.size();
        for(int z=0;z<s;z++)
        {
            int t=q.front();
            q.pop();

            if(t==target)
                return level;

            for(int x : bsmap[t]) // for each bus in that stop
            {
                if(!bV[x]) 
                {
                    for(int y : routes[x]) // for each stop that bus can go
                    {
                        if(!bsVis[y])
                        {
                            bsVis[y]=true;
                            q.push(y);
                        }
                    }
                    bV[x]=true;
                }
            }
        }
        level++;
       }
       return -1;
    }
};