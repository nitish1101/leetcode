class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        int n=gain.size(); int g=0;
        for(int i=0;i<n;i++)
        {
            g+=gain[i];
            maxi=max(maxi,g);
        }
        return maxi;
    }
};

