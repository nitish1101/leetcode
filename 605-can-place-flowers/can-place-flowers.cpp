class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int s=f.size();
        int i=0; int flag=0;
        while(i<s && n!=0)
        {
            flag=1;
            if(f[i]==1)
                i+=2;
            else
            {
               if(i-1 >= 0 && f[i-1]!=0) {
                flag=0;
               }
               if(i+1 < s && f[i+1]!=0) {
                flag=0;
               }
               if(flag==1) {
                f[i]=1;i+=2;n--;
               }
               else
               {
                i++;
               }

            }
        }
        return n==0;
    }
};