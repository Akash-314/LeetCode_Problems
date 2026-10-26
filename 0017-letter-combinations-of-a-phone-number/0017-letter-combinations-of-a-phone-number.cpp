class Solution {
public:
    int n;
    vector<string> ans;
    void f(string d, vector<string>& alp, int i, string s) {
        if (i == n) {
            ans.push_back(s);
            return;
        }
        int c = d[i] - '0';
        for (int j = 0; j < alp[c - 1].size(); j++) {
            s.push_back(alp[c - 1][j]);
            f(d, alp, i + 1, s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        vector<string> alp = {"", "abc",  "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s;
        f(digits, alp, 0, s);
        return ans;
    }
};