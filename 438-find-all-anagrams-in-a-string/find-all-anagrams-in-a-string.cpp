class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int n = s.size(), m = p.size();
        if (m > n) return result;
        int need[26] = {}, have[26] = {};
        for (char c : p) ++need[c - 'a'];
        for (int i = 0; i < n; ++i) {
            ++have[s[i] - 'a'];
            if (i >= m) --have[s[i - m] - 'a'];          // slide the window
            if (i >= m - 1 && equal(begin(have), end(have), begin(need)))
                result.push_back(i - m + 1);
        }
        return result;
    }
};
