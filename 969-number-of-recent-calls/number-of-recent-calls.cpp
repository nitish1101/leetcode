class RecentCounter {
    vector<int> v;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        v.push_back(t);
        int idx=lower_bound(v.begin(),v.end(),t-3000)-v.begin();
        return v.size()-idx;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

 /***

>= t-3000 ---- >=2

1,100,3001,3002

find the lower_bound of t-3000
return i-idx;




 */