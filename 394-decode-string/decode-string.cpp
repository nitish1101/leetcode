class Solution {
public:

    bool isInteger(string s) {
    if (s.empty())
        return false;

    for (char c : s) {
        if (!isdigit(static_cast<unsigned char>(c)))
            return false;
    }

    return true;
}

    string decodeString(string s) {
        // stack
        // until stack is empty();
        //     push except for] 
        //     when ]  pop until [  + all conssecutive digits
        //     for the string popped, append it the number times and push back to the stack

        stack<string> st;
        st.push(string(1,s[0]));

        int i=1; int l=s.length();
        while(!st.empty() && i<l)
        {
            if( string(1,s[i]) != "]")
            {
                st.push( string(1,s[i]));
            }
            else
            {
                string tmp="";
                string m="";
                while(!st.empty() && st.top()!="[")
                {
                    tmp  = st.top() + tmp;
                    st.pop();
                }
                st.pop();

                while(!st.empty() && isInteger(st.top())==true)
                {
                    m=st.top() + m;
                    st.pop();
                }

                int x = stoi(m);
                string ss=tmp;
                for(int j=1;j<x;j++)
                    ss += tmp;


                st.push(ss);
            }
            i++;
        }
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};

/**




*/