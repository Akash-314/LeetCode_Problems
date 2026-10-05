class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<char> st;
        int scr = 0;
        int depth = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                depth--;
                if (s[i - 1] == '(') {
                    scr += (1 << depth);
                }
            } else {
                depth++;
            }
        }
        return scr;
    }
};