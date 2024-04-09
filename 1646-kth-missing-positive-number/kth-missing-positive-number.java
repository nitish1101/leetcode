class Solution {
    public int findKthPositive(int[] arr, int k) {
        List<Integer> list=new ArrayList<Integer>(Collections.nCopies(2001,0));
        for(int i : arr)
            list.set(i,1);
        
        int c=0; int ans=0;
        for(int i=1;i<list.size();i++)
        {
            if(list.get(i)==0)
                c++;
            if(c==k){
                ans=i;
                break;
            }

        }
        return ans;
    }
}

/**



 */