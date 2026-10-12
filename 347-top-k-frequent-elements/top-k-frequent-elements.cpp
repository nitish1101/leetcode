class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // hash map => n
        // x.log(n)

        //n+x logn
        //x, k
        int n=nums.size();
        unordered_map<int, int> fmap(n+1);
        
        for(int x : nums)
            fmap[x]++;
        
        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;

        for(auto x : fmap)
        {
            pq.push({x.second,x.first});
            if(pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};