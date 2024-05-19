class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[l] <= nums[mid]) {
                if(target >= nums[l] && target < nums[mid])
                    h=mid-1;
                else
                    l=mid+1;
            }
            else {
                 if(target > nums[mid] && target <= nums[h])
                    l=mid+1;
                else
                    h=mid-1;
            }
        }
        return -1;  
    }
};




/***

4,5,6,7,0,1,2  0
1,3            1,2,3
3,1,           1,2,3


*/




