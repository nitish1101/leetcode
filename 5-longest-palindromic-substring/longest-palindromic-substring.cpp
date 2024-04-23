class Solution {
public:
    string longestPalindrome(string s) {
        //a , aa
        int n=s.length();
        int i=0,j=0;
        int ans=0; string res="";
        if(n==1)
            return s;
        for(int k=0;k<n;k++)
        {
            i=k,j=k;
            while(i>=0 && j<n && s[i]==s[j])
            { 
                if((j-i+1) > ans)
                {
                    ans=j-i+1;
                    res=s.substr(i,ans);

                }  
                i--;
                j++;
                
            }
        }
        for(int k=0;k<n-1;k++)
        {
            i=k,j=k+1;
            while(i>=0 && j<n && s[i]==s[j])
            {   
                if((j-i+1) > ans)
                {
                    ans=j-i+1;
                    res=s.substr(i,ans);

                }
                i--;
                j++;
                
            }
        }
        return res;








        
    }
};