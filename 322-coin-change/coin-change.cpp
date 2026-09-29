class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int unreachable = amount + 1;
        vector<int> fewest(amount + 1, unreachable);
        fewest[0] = 0;

        for (int total = 1; total <= amount; ++total) {
            for (int coin : coins) {
                if (coin <= total) {
                    fewest[total] = min(fewest[total], fewest[total - coin] + 1);
                }
            }
        }
        return fewest[amount] == unreachable ? -1 : fewest[amount];
    }
};
