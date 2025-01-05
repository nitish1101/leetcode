class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string ss="";
        for(char c : s)
        {
            if(c==' ')
            {
                cout<<ss<<endl;
                if(ss.length()!=0)
                {
                    v.push_back(ss);
                    ss="";
                }
            }
            else
            {
                ss+=c;
            }
        }
        if(ss.length()!=0)
            v.push_back(ss);
        string res="";
        for(int i=v.size()-1; i>=0;i--)
        {
            res+=v[i]+" ";
        }
        return res.substr(0,res.length()-1);
    }
};