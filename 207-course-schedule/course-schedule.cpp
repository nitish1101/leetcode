class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> next(numCourses);
        vector<int> indegree(numCourses, 0);
        for (const auto& edge : prerequisites) {
            next[edge[1]].push_back(edge[0]);
            ++indegree[edge[0]];
        }

        queue<int> ready;
        for (int course = 0; course < numCourses; ++course) {
            if (indegree[course] == 0) ready.push(course);
        }

        int completed = 0;
        while (!ready.empty()) {
            int course = ready.front();
            ready.pop();
            ++completed;
            for (int after : next[course]) {
                if (--indegree[after] == 0) ready.push(after);
            }
        }
        return completed == numCourses;
    }
};
