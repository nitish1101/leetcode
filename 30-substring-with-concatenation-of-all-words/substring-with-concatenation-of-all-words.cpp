class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int l = words.size();
        int n = s.length();
        int k = words[0].size();
        
        if (l == 0 || n == 0 || k == 0) return ans;

        unordered_map<string,int> mp;
        for(auto word: words) {
            mp[word]++;
        }

        for (int i = 0; i < k; ++i) {
            int left = i;
            unordered_map<string, int> seen;
            int count = 0;

            for (int j = i; j <= n - k; j += k) {
                string word = s.substr(j, k);
                if (mp.find(word) != mp.end()) {
                    seen[word]++;
                    count++;

                    while (seen[word] > mp[word]) {
                        string tempWord = s.substr(left, k);
                        seen[tempWord]--;
                        count--;
                        left += k;
                    }

                    if (count == l) {
                        ans.push_back(left);
                        string tempWord = s.substr(left, k);
                        seen[tempWord]--;
                        count--;
                        left += k;
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = j + k;
                }
            }
        }
        return ans;
    }
};
