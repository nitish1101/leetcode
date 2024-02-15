class Solution {
public:
    vector<string> ans;
    bool isValid(vector<char> v)
    {
        stack<char> s;
        if(v[0]==')')
            return false;
        s.push(v[0]);
        int i=1;
        while(i<v.size())
        {
            if(v[i]=='(')
                s.push(v[i]);
            else 
            {
                if(s.empty())
                    return false;
                s.pop();
            }
            i++;
        }
        if(!s.empty())
            return false;
        return true;
    }

    string convertToString(vector<char>& v)
    {
        string s="";
        for(auto e: v)
            s+=e;
        return s;
    }


    void f(int n,vector<char> v,vector<char>& tmp)
    {
        if(tmp.size() == n)
        {
            for(int k=0;k<n;k++)
                cout<<tmp[k];
            cout<<endl;
            if(isValid(tmp))
                ans.push_back(convertToString(tmp));
            return;   
        }
        for(int i=0;i<2;i++)
        {
                tmp.push_back(v[i]);
                f(n,v,tmp);
                tmp.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<char> v({'(',')'});
        vector<char> tmp;
        f(2*n,v,tmp);
        return ans;
    }
};