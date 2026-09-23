class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1);
        int best = 0;
        int left = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            unsigned char ch = s[right];
            if (lastSeen[ch] >= left) {
                left = lastSeen[ch] + 1;
            }
            lastSeen[ch] = right;
            best = max(best, right - left + 1);
        }

        return best;
    }
};
