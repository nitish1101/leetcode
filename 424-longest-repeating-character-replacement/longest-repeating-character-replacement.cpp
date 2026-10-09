#include <algorithm>
#include <array>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        array<int, 26> counts{};
        int left = 0;
        int best = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            ++counts[s[right] - 'A'];
            // All but the most frequent character need replacement.
            while (right - left + 1 - *max_element(counts.begin(), counts.end()) > k) {
                --counts[s[left] - 'A'];
                ++left;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
// Time: O(26 * n) = O(n). Auxiliary space: O(26) = O(1).
