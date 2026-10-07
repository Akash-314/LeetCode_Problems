class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;
    int mxLen = 0;
    void f(string& s, int i, int cnt, string& curr) {
        if (cnt < 0)
            return;
        if (i == s.size()) {
            if (cnt == 0) {
                if (curr.size() > mxLen) {
                    mxLen = curr.size();
                    st.clear();
                }
                if (curr.size() == mxLen) {
                    st.insert(curr);
                }
            }
            return;
        }
        if (s[i] != '(' and s[i] != ')') {
            curr.push_back(s[i]);
            f(s, i + 1, cnt, curr);
            curr.pop_back();
            return;
        }
        curr.push_back(s[i]);
        f(s, i + 1, cnt + (s[i] == '(' ? 1 : -1), curr);
        curr.pop_back();
        f(s, i + 1, cnt, curr);
    }
    vector<string> removeInvalidParentheses(string s) {
        string curr = "";
        f(s, 0, 0, curr);
        for (auto x : st) {
            ans.push_back(x);
        }
        return ans;
    }
};