class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {};
        for (char c : tasks) ++freq[c - 'A'];
        int maxF = *max_element(freq, freq + 26);        // busiest task
        int nMax = count(freq, freq + 26, maxF);         // how many share that count
        int total = tasks.size();
        // Fill the busiest task's gaps with other tasks or idle time.
        return max(total, (maxF - 1) * (n + 1) + nMax);
    }
};
