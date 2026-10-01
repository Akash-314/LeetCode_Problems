class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n == 1) return false;
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }
            if (s[i] == ')') {
                if (st.top() == '(') {
                    st.pop();
                    continue;
                } else
                    return false;
            } else if (s[i] == ']') {
                if (st.top() == '[') {
                    st.pop();
                    continue;
                } else
                    return false;
            } else if (s[i] == '}') {
                if (st.top() == '{') {
                    st.pop();
                    continue;
                } else
                    return false;
            } else {
                st.push(s[i]);
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};