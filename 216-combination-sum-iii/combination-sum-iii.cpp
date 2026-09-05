class Solution {
public:
    void rec(int i, int k, int t, vector<int>& ds, vector <vector<int>> &ans) {
        if (t==0 && k==0) {
            ans.push_back(ds);
            return;
        }

        if (t < 0 || k==0 || i>9)
            return;
        
        //pick
        ds.push_back(i);
        rec(i+1,k-1,t-i,ds,ans);
        ds.pop_back();

        //np
        rec(i+1,k,t,ds,ans);
    }

    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int> ds;
        vector <vector<int>> ans;
        rec(1,k,target,ds,ans);
        return ans;
    }
};

/**


[1,2,...9]
atmost once
k=3
t=7

1,2,4 , k=3

1,6

2,5

3,4



f(i,k,t,ds,ans)


if(!t && !k))
    ans.add(ds);
    return;
if(t<0)
    return;
if(!k)
    return;
if(i>9)
    return;

//pick
ds.add(i);
rec(i+1,k-1,t-i,ds,ans);
ds.remove(i);

//not pick
rec(i+1,k,t,ds,ans);


*/
