#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1, 0);
        // Shifting removes the last bit, which contributes either 0 or 1.
        for (int i = 1; i <= n; ++i)
            bits[i] = bits[i >> 1] + (i & 1);
        return bits;
    }
};
