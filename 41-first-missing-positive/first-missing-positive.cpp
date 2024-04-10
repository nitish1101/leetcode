class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<=100001;i++)
        {
            if(binary_search(nums.begin(),nums.end(),i)==false)
                return i;
        }
        return 0;
    }
};