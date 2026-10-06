class Solution {
public:
    int maxJump(vector<int>& stones) {

            int n=stones.size();
            int ans=0;
            for(int i=0;i<n-1;i++)
            {
                int nxt=stones[i+2];
                if(i==n-2)
                    nxt=stones[i+1];
                ans=max(ans,abs(stones[i]-nxt));
            }
            return ans;
        
    }
};





