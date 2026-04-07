class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        unordered_map<string,char> mp2;
        int l1=pattern.length();
        vector<string> arr;
        string tmp="";
        for(int i=0;i<s.length();i++)
        {
            
            if(s[i]!=' ')
                tmp+=s[i];
            else
            {
                arr.push_back(tmp);
                tmp="";
            }
        }
        arr.push_back(tmp);
        int l2=arr.size();
        if(l1!=l2)
            return false;
        for(int i=0;i<l1;i++)
        {
            if(mp.find(pattern[i])==mp.end())
                mp[pattern[i]]=arr[i];
            else if(mp[pattern[i]]!=arr[i])
                return false;
            
            if(mp2.find(arr[i])==mp2.end())
                mp2[arr[i]]=pattern[i];
            else if(mp2[arr[i]]!=pattern[i])
                return false;
        }
        return true;
    }
};