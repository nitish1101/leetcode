class Solution {
public:
    string reorganizeString(string s) {
        int l=s.length();
        vector<int> freq(26,0);

        for(char c : s)
            freq[c-'a']++;

        priority_queue<pair<int,char>> pq;

        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
                pq.push({freq[i],char('a'+i)});
        }
        
        for (int f : freq) {
            if (f > (l + 1) / 2)
                return "";
        }

        int k=0;
        vector<char> ans(l,' ');

        while(!pq.empty())
        {
            pair<int,char> top=pq.top();
            pq.pop();

            for(int i=0;i<top.first;i++)
            {
                if(k>=l)
                    k=1;

               
                ans[k]=top.second;
                k+=2;
            }
        }

        return string(ans.begin(),ans.end());
    }
};