class Solution {
public:
    bool isNum(char c)
    {
        return (c >= '0' && c <='9') ? true : false;
    }

    string decodeString(string s) {
        stack<string> s1;
        string ans="";
        int l=s.length();
        
        for(char c : s)
        {
            if(c==']')
            {
                string x1="";
                while(!s1.empty() && s1.top()!="[") 
                {
                    x1 = s1.top() + x1; //a //
                    s1.pop();
                }

                s1.pop();

                string a="";
                while(!s1.empty() && isNum(s1.top()[0]))
                {
                    a=s1.top()+a;
                    s1.pop();
                }
                int aa=stoi(a); //3

                string x2="";
                for (int i = 1; i <= aa; ++i)
                    x2+=x1; //aaa
                
                s1.push(x2);  //aaa 
            }
            else
                s1.push(string(1,c));
        }
        while(!s1.empty())
        {
            ans=s1.top()+ans;
            s1.pop();
        }
        return ans;
    }
};


/***
ans=
a
a
a
c
c
[3[a21[c]]

2c
3a

[



*/