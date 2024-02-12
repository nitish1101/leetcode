class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        string s1=ransomNote;
        string s2=magazine;
        int l1=s1.length();
        int l2=s2.length();
        if(l1>l2)
            return false;
        int f2[26]={0};
        for(int i=0;i<l2;i++)
        {
            f2[s2[i]-'a']++;
        }
        for(int i=0;i<l1;i++)
        {
            if(!f2[s1[i]-'a'])
                return false;
            f2[s1[i]-'a']--;
        }
        return true;
        
    }
};