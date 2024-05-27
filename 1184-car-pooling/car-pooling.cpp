class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int s=0;
        for(int i=0;i<=1000;i++){
            for(int j=0;j<trips.size();j++){
                if(i==trips[j][1])s+=trips[j][0];
                if(i==trips[j][2])s-=trips[j][0];
            }
            if(s>capacity)return 0;
            cout<<s<<" ";
        }
        return 1;
    }
};