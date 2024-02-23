class Solution {
public:

static bool compare(string a,string b){
    return a+b > b+a;
}
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto e: nums)
        {
            v.push_back(to_string(e));
        }
        sort(v.begin(),v.end(),compare);
        // reverse(v.begin(),v.end());
        string s="";
        for(auto e: v)
            s=s+e;
        if(s[0]=='0')
            return "0";
        return s;
        
    }
};