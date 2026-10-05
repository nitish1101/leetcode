class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(),courses.end(), compare);
        
        priority_queue<int> pq;

        int tD=0;
        for(auto x : courses)
        {
            if(x[0] <= x[1]) {
                if(tD+x[0] <= x[1]){
                    tD+=x[0];
                    pq.push(x[0]);
                }
                else
                {
                    if(pq.empty())
                        continue;
                    auto y= pq.top();
                    if(x[0] < y )
                    {
                        pq.pop();
                        tD = tD - y + x[0];
                        pq.push(x[0]);
                    }
                }
            }
        }
        return pq.size();   
    }
};


/****
sort by lastDay
now pick one by one
totDuration+=duration[i];
if(td>lastDay)
    skip it 
*/