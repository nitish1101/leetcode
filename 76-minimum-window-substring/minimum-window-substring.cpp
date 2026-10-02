#include <string>
#include <vector>
#include <climits>
using namespace std;

// LeetCode 76: Minimum Window Substring
// Sliding window with a need-count per character. Expand right until the window
// covers all of t, then shrink from the left while it still does.
// Time: O(m + n), Space: O(1) (fixed 128-size table)
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) return "";
        vector<int> need(128, 0);
        for (char c : t) need[(unsigned char)c]++;
        int missing = (int)t.size();
        int bestStart = 0, bestLen = INT_MAX;
        int left = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            if (need[(unsigned char)s[right]]-- > 0) missing--;
            while (missing == 0) {
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestStart = left;
                }
                if (++need[(unsigned char)s[left]] > 0) missing++;
                left++;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};
