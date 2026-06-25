class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        int n=s.length();
        int j=0;
        while(j<n)
        {
            if(s[j] != '*')
                stk.push(s[j]);
            else
                stk.pop();

            j++;
        }
        string ans;
        while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

/* *        
l e e t * * c o d * e
*



e
o
c
e
l
*/



 



