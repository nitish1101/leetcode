#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1=word1.length();
        int l2=word2.length();
        int i=0,j=0;
        string ans="";
        while(i<l1 && j<l2)
        {
            ans+=word1[i];
            ans+=word2[j];
            i++;j++;
        }
        if(i<l1)
            ans+=word1.substr(i,l1);
        if(j<l2)
            ans+=word2.substr(j,l2);
       return ans;
    }
};