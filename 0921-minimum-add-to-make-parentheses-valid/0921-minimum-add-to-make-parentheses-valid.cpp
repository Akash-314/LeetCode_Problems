class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        int i = 0;
        //(()())((
        while (i < n) {
            if (!st.empty() and s[i] == ')' and st.top() == '(') {
                if (!st.empty() and st.top() == '(') {
                    st.pop();
                    // continue;
                }
            } else
                st.push(s[i]);
            i++;
        }
        return (int)st.size();
    }
};