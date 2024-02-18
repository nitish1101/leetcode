class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        int n=beginWord.length();
        unordered_set<string> wl(wordList.begin(),wordList.end());
        unordered_set<string> vis;
         if(wl.find(endWord)==wl.end())
            return 0;
        q.push(beginWord);
        vis.insert(beginWord);int level=1;
        while(!q.empty())
        {
            int l=q.size();
            while(l--)
            {
                string tmp=q.front();
                q.pop();
                string cpy=tmp;
                for(int i=0;i<26;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        cpy[j]=(char)(97+i);
                        if(cpy==endWord)
                            return level+1;
                        if(vis.find(cpy)==vis.end() && wl.find(cpy)!=wl.end())
                        {
                            q.push(cpy);
                            vis.insert(cpy);
                        }
                        cpy=tmp;
                    } 
                }
            }
            level++;
        }
        return 0;
        
    }
};