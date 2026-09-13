class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.size() && ast[i] < 0 && st.top() > 0) {
                if (abs(st.top()) < abs(ast[i])) {
                    while (st.size() && abs(st.top()) < abs(ast[i]) &&
                           st.top() > 0)
                        st.pop();
                }
                if (st.size() && st.top() > 0 &&
                    abs(st.top()) == abs(ast[i])) {
                    st.pop();
                    continue;
                }
                if (st.size() && st.top() > 0 &&
                    abs(st.top()) > abs(ast[i])) {
                    continue;
                }
            }
            st.push(ast[i]);
        }

        vector<int> ans;
        while (st.size()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};