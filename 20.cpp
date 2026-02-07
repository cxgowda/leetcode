class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // If opening bracket, push to stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // If closing bracket
            else {
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // Stack should be empty at the end
        return st.empty();
    }
};