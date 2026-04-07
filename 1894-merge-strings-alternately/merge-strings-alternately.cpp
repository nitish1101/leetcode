#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1=word1.length();
        int l2=word2.length();
        
        string ans="";
        for(int i=0;i<max(l1,l2);i++)
        {
            if(i<l1)
                ans+=word1[i];
            if(i<l2)
                ans+=word2[i];
        }
       return ans;
    }
};