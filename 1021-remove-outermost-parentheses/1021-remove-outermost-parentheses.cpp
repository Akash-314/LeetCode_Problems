class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack<char> st;
        int cnt = 0;
        string ans = "";
        bool ok = false;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') cnt++;
            else cnt--;
            if((cnt == 1 and !ok) or cnt == 0){
                ok = !ok;
                continue;
            }
            else st.push(s[i]);

            ans += st.top();
        }
        // while(!st.empty()){
        //     ans += st.top();
        //     st.pop();
        // }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};