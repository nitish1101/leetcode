class Solution {
public:
    bool isOperator(string s)
    {
        return (s=="+" || s=="-" || s=="*" || s=="/" );
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(auto e : tokens)
        {
            if(isOperator(e))
            {
                int b = stoi(s.top());
                s.pop();
                int a=stoi(s.top());
                s.pop();

                if(e=="+")
                    s.push(to_string(a+b));
                else if(e=="-")
                    s.push(to_string(a-b));
                else if(e=="*")
                    s.push(to_string(a*b));
                else
                    s.push(to_string(a/b));
            }
            else
            {
                s.push(e);
            }
        }
        return stoi(s.top());
    }
};