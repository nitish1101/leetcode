class Solution {

    public int maxCount(int[] banned, int n, int maxSum) {
        HashSet<Integer> bs=new HashSet<>();
        for(int i : banned)
            bs.add(i);
        int c=0;
        for(int i=1;i<=n;i++)
        {
           if(bs.contains(i)==false){
                if(maxSum-i >= 0){
                    c++;
                    maxSum-=i;
                }
                else
                    break;
           }
        }
        return c; 
    }
}