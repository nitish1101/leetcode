class Solution {
public:
    string addBinary(string a, string b) {
        int l1=a.length();
        int l2=b.length();
        int i=l1-1;
        int j=l2-1;
        int c=0;string s="";
        while(i>=0 && j>=0)
        {
            int x=c+int(a[i]-'0')+int(b[j]-'0');
            cout<<x<<" ";
            c=0;
            if(x/2)
                c=1;
            s+=to_string(x%2);
            cout<<s<<endl;
            i--;
            j--;
        }
        while(i>=0)
        {
             int x=c+int(a[i]-'0');
            c=0;
            if(x/2)
                c=1;
            s+=to_string(x%2);
            i--;
        }
        while(j>=0)
        {
           int x=c+int(b[j]-'0');
            c=0;
            if(x/2)
                c=1;
            s+=to_string(x%2);
            j--;
        }
        if(c)
            s=s+to_string(c);
        
        reverse(s.begin(),s.end());
        return s;

    }
};