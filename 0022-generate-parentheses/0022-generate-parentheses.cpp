class Solution {
public:
    void GenParen(vector<string>& ans, string s, int x, int y, int n) {
        if (y == n) {
            ans.push_back(s);
            return;
        }
        if (x < n)
            GenParen(ans, s + "(", x + 1, y, n);
        if (y < x)
            GenParen(ans, s + ")", x, y + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        GenParen(ans, "", 0, 0, n);
        return ans;
    }
};