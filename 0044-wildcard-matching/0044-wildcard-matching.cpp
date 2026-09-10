class Solution {
public:
    int m, n;
    // int dp[2001][2001];
    // bool f(string s, string p, int i, int j) {
    //     if (i == m and j == n)
    //         return true;
    //     if (j == n and i < m)
    //         return false;
    //     if (i == m and j < n) {
    //         for (int k = j; k < n; k++) {
    //             if (p[k] != '*')
    //                 return false;
    //         }
    //         return true;
    //     }

    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     if (p[j] == '?' or s[i] == p[j]) {
    //         return dp[i][j] = f(s, p, i + 1, j + 1);
    //     } else if (p[j] == '*') {
    //         return dp[i][j] = f(s, p, i, j + 1) or f(s, p, i + 1, j);
    //     }
    //     return dp[i][j] = false;
    // }
    bool isMatch(string s, string p) {
        // memset(dp, -1, sizeof(dp));
        m = s.size(), n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
        dp[m][n] = true;
        for (int j = n - 1; j >= 0; j--) {
            if (p[j] == '*')
                dp[m][j] = dp[m][j + 1];
            else
                dp[m][j] = false;
        }
        for (int i = 0; i < m; i++)
            dp[i][n] = false;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (p[j] == '?' || p[j] == s[i]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else if (p[j] == '*') {
                    dp[i][j] = dp[i][j + 1] || dp[i + 1][j];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[0][0];
    }
};