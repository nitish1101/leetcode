class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        static const char* letters[10] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> result;
        string cur;
        function<void(int)> dfs = [&](int i) {
            if (i == (int)digits.size()) { result.push_back(cur); return; }
            for (const char* p = letters[digits[i] - '0']; *p; ++p) {
                cur.push_back(*p);
                dfs(i + 1);
                cur.pop_back();
            }
        };
        dfs(0);
        return result;
    }
};
