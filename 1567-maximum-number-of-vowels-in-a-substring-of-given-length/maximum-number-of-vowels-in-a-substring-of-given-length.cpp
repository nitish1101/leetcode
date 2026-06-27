class Solution {
public:
    bool isVowel(char c)
    {
        unordered_set<char> st={'a','e','i','o','u'};
        if(st.find(c)!=st.end())
            return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int n=s.length();
        int i=1,j=k;
        int maxi=0;
        for(int x=0;x<k;x++)
        {
            if(isVowel(s[x]))
                maxi++;
        }
        int c=maxi;
        while(j<n)
        {
            if(isVowel(s[i-1]))
                c--;
            if(isVowel(s[j]))
                c++;
            maxi=max(maxi,c);
            i++;
            j++;
        }
        return maxi;
    }
};



   


