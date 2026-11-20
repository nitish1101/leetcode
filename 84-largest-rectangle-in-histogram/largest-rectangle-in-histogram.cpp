#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;               // indices with strictly increasing heights
        int best = 0;
        int n = (int)heights.size();
        for (int i = 0; i <= n; ++i) {
            int h = (i < n) ? heights[i] : 0;  // sentinel flushes the stack
            while (!st.empty() && heights[st.top()] > h) {
                int height = heights[st.top()];
                st.pop();
                int left = st.empty() ? 0 : st.top() + 1;
                best = max(best, height * (i - left));
            }
            st.push(i);
        }
        return best;
    }
};
