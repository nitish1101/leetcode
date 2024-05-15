class Solution {
public:
    int minDeletions(string s) {
        int l=s.length();

        vector<int> arr(26,0);
        for(auto c : s)
            arr[c-'a']++;
        sort(arr.begin(),arr.end(),greater<int>());
        int maxi=arr[0];
        
        set<int> st;
        
        int ans=0;
        for(int i=0;i<26 ;i++)
        {
            if(arr[i] == 0)
                continue;
            
            if(st.find(arr[i])==st.end())
                st.insert(arr[i]);
            else
            {
                while(st.find(arr[i])!=st.end())
                {
                    arr[i]--;
                    ans++;
                }
                if(arr[i]!=0)
                    st.insert(arr[i]);
            }
        }
            return ans;
        
    }
};