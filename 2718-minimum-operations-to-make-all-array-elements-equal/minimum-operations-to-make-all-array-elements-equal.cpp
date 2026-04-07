class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<int> arr(nums.begin(),nums.end());
        sort(arr.begin(),arr.end());
        long long int n=arr.size();
        vector<long long> anss;
        vector<long long> ps; long long int s=0;
        
        for(int i=0;i<n;i++){
            s=s+arr[i];
            ps.push_back(s);
        }
        for(int q: queries) {
            long long int idx=upper_bound(arr.begin(),arr.end(),q)-arr.begin();
            long long int nb=idx;
            long long int na=n-idx;
            long long ans=0;

            if(idx>0)
                ans=(q*nb-ps[idx-1])+(ps[n-1]-ps[idx-1]-(q*na));
            else
                ans=ps[n-1]-(q*na);

            anss.push_back(ans);
        }
        return anss;
        
    }
};