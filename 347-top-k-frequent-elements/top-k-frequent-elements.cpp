struct Compare {
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2) const {
        return p1.second > p2.second ;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i : nums)
            mp[i]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        
        for(auto &[key,val] : mp) {

            pair<int, int> p = {key, val};
            pq.push(p);
            if(pq.size() > k)
                pq.pop();
            
            
        }
        vector<int> ans;
        while(!pq.empty())
        {
            pair<int,int> p=pq.top();
            pq.pop();
            ans.push_back(p.first);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};




