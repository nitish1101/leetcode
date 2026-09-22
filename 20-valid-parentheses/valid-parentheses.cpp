class Solution {
public:
    bool isValid(string s) {
        stack<char> openings;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                openings.push(ch);
            } else {
                if (openings.empty()) {
                    return false;
                }

                char open = openings.top();
                openings.pop();

                if ((ch == ')' && open != '(') ||
                    (ch == ']' && open != '[') ||
                    (ch == '}' && open != '{')) {
                    return false;
                }
            }
        }

        return openings.empty();
    }
};
