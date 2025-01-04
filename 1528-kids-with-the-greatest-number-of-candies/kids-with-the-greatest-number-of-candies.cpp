#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=INT_MIN;
        for(int c : candies)
            maxi=max(c,maxi);
        vector<bool> ans(candies.size(),false);
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extraCandies >= maxi)
                ans[i]=true;
        }
        return ans;
    }
};