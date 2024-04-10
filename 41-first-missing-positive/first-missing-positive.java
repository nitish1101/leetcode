class Solution {
    public int firstMissingPositive(int[] nums) {
        HashSet<Integer> set=new HashSet<>();
        for(int i : nums)
            set.add(i);
        
        for(int i=1;i<=set.size()+1;i++)
            if(set.contains(i)==false)
                return i;
        return 0;       
    }
}