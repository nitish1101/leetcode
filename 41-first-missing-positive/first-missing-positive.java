class Solution {
    public int firstMissingPositive(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length;
        for(int i=1;i<=n+1;i++)
            if(Arrays.binarySearch(nums,i) < 0)
                return i;
        return 0;
        
    }
}