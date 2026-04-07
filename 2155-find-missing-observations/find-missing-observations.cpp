class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = mean * (n + m);
        int s = accumulate(rolls.begin(), rolls.end(), 0); // Calculate current sum of rolls
        int target = total - s; // Calculate target sum
        
        if (target < n || target > n * 6) // Check if target is out of range
            return {};
        
        int minRoll = target / n; // Calculate minimum value each missing roll should have
        int remaining = target % n; // Calculate remaining value after distributing minRoll to each missing roll
        
        vector<int> ans(n, minRoll); // Initialize vector with minimum roll values
        
        for (int i = 0; i < remaining; ++i) {
            ans[i]++; // Distribute remaining value to first 'remaining' rolls
        }
        
        return ans;
    }
};
