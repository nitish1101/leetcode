class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n=points.size();
        int c=0;
        for(int i=0;i<n;)
        {
            int os=points[i][0];
            int oe=points[i][1];
            int j=i+1;c++;
            while(j<n && points[j][0] <= oe){
                    os=points[j][0];
                if(points[j][1] < oe)
                    oe=points[j][1];
                j++;
            }
            i=j;
        }
        return c;
    }
};