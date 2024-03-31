class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==1)
            return s;
        
        int j=0,k=0;
        int maxi=0;
        string maxis="";
        for(int i=0;i<n;i++)
        {
            j=i;k=i;
            while(j>=0 && k<n && s[j]==s[k])
            {
                if(maxi < (k-j+1))
                {
                    maxi=k-j+1;
                    maxis=s.substr(j,maxi);
                }
                j--;
                k++;
                
            }
        }
        for(int i=0;i<n;i++)
        {
            j=i;k=i+1;
            while(j>=0 && k<n && s[j]==s[k])
            {
                if(maxi < (k-j+1))
                {
                    maxi=k-j+1;
                    maxis=s.substr(j,maxi);
                }
                j--;
                k++; 
            }
        }
        return maxis;

    }
};