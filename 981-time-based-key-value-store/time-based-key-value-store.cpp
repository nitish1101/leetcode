class TimeMap {
    unordered_map<string, vector<pair<int,string>>> store;
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});  // timestamps arrive strictly increasing
    }

    string get(string key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) return "";
        auto& v = it->second;
        // Binary search: last entry with ts <= timestamp.
        int lo = 0, hi = (int)v.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid].first <= timestamp) lo = mid + 1;
            else hi = mid;
        }
        return lo == 0 ? "" : v[lo - 1].second;
    }
};
