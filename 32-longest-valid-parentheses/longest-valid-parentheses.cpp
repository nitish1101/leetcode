#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int best = 0, open = 0, close = 0, n = (int)s.size();
        // Left to right: reset when close exceeds open.
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') ++open; else ++close;
            if (open == close) best = max(best, 2 * close);
            else if (close > open) open = close = 0;
        }
        open = close = 0;
        // Right to left: reset when open exceeds close.
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(') ++open; else ++close;
            if (open == close) best = max(best, 2 * open);
            else if (open > close) open = close = 0;
        }
        return best;
    }
};
