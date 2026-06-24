class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        unordered_map<int,int> freq;
        int ans=0;
       for (int x : nums) {
        int need = k - x;

        if (freq[need] > 0) {
            ans++;
            freq[need]--;
        } else {
            freq[x]++;
        }
    }
    return ans;
    }
};

/**
2,1,3,4//5

mp[nums[i]]=k-nums[i];

2->3
1->4
ans=1


1,2,2,5,5,6,7 //7

6
mp[1]++

5
mp[2]++

5
1:0 2:0

2
a=1

2
a=2

1
a=3

6












*/

