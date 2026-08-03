class Solution {
public:
    string predictPartyVictory(string senate) {
        int l=senate.length();
        queue<int> r,d;

        for(int i=0;i<l;i++)
        {
            if(senate[i]=='R')
                r.push(i);
            else
                d.push(i);
        }

        while(!r.empty() && !d.empty())
        {
            int rr=r.front();
            int dd=d.front();
            r.pop();
            d.pop();
            if(rr<dd)
            {
                r.push(rr+l);
            }
            else
            {
                d.push(dd+l);
            }
        }
        return d.empty()?"Radiant":"Dire";
    }
};