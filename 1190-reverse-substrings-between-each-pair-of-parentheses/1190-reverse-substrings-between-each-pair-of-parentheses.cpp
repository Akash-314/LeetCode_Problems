class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<char> st;
        int i = 0;
        string ans = "";
        while (i < n) {
            if (s[i] != ')')
                st.push(s[i]);
            else {
                string a = "";
                while (!st.empty() and st.top() != '(') {
                    a += st.top();
                    st.pop();
                }
                st.pop();
                for (int j = 0; j < a.size(); j++) {
                    st.push(a[j]);
                }
            }
            i++;
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};