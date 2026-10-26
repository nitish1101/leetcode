class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        priority_queue<int, vector<int>, greater<int>> ends;  // end times of rooms in use
        int rooms = 0;
        for (auto& m : intervals) {
            while (!ends.empty() && ends.top() <= m[0]) ends.pop();  // freed rooms
            ends.push(m[1]);
            rooms = max(rooms, (int)ends.size());
        }
        return rooms;
    }
};
