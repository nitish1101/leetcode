class Solution {
public:
    int gcd(int a, int b)
    {
        if(a==0)
            return b;
        if(b==0)
            return a ;
        return gcd(b,a%b);
    }
    string gcdOfStrings(string str1, string str2) {
        int l1=str1.length();
        int l2=str2.length();
        int g=gcd(l1,l2);
        string ans=str1.substr(0,g);
        string s1="";
        string s2="";
        for(int i=0;i<max(l1/g,l2/g);i++) {
            if(i<l1/g)
                s1+=ans;
            if(i<l2/g)
                s2+=ans;
        }

        if(s1==str1 && s2==str2)
            return ans;
        return "";
        
    }
};