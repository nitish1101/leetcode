class Solution {
public:

    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;

        while(l<h)
        {
            int mid= l+(h-l)/2;
            if(nums[mid] < nums[mid+1])
                l=mid+1;
            else
                h=mid;
        }
        return l;
    }
};


/**

7 6 5 4 9 8 -> 9
1 2 3 4 1 -> 4


*/