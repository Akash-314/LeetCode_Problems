class Solution {
public:
    int dp[105][105];
    bool f(string& s, int i, int cnt) {
        if (i == s.size()) {
            if (cnt == 0)
                return true;
            else
                return false;
        }
        if (cnt < 0)
            return false;
        if (dp[i][cnt] != -1)
            return dp[i][cnt];
        if (s[i] == '(') {
            return dp[i][cnt] = f(s, i + 1, cnt + 1);
        } else if (s[i] == ')') {
            return dp[i][cnt] = f(s, i + 1, cnt - 1);
        } else {
            return dp[i][cnt] = f(s, i + 1, cnt + 1) || f(s, i + 1, cnt - 1) ||
                                f(s, i + 1, cnt);
        }
    }
    bool checkValidString(string s) {
        memset(dp, -1, sizeof dp);
        return f(s, 0, 0);
    }
};