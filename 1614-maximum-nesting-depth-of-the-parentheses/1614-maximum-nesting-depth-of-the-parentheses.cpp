class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        stack<int> st;
        int i = 0, j = n-1, cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == ')'){
                cnt = max(cnt, (int)st.size());
                st.pop();
                continue;
            }
            if(s[i] == '(') st.push(s[i]);
        }
        return cnt;
    }
};