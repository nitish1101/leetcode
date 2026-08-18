class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n=asteroids.size();
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            flag=false;
            while(!s.empty() && s.top() > 0 && asteroids[i] < 0)
            {
                    if(abs(s.top()) < abs(asteroids[i]))
                        s.pop();
                    else if(abs(s.top()) == abs(asteroids[i])){
                        s.pop();
                        flag=true;
                        break;
                    }
                    else
                    {
                        flag=true;
                        break;
                    }
            }
            if(!flag)
                s.push(asteroids[i]);
        }
        vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};