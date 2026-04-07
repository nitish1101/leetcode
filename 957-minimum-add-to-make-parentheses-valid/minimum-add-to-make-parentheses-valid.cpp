class Solution {
public:
    int minAddToMakeValid(string str) {
        int n=str.length();
        stack<int> s; int p=0,q=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='(')
                s.push(str[i]);
            else
            {
                if(s.empty())
                    p++;
                else
                    s.pop();
                }
        }
        while(!s.empty())
        {
            q++;
            s.pop();
        }
        return p+q;      
    }
};