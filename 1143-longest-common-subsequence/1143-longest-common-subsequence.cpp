class Solution {
public:
    // int dp[1001][1001];
    // int f(string& s, string& t, int i, int j) {
    //     if (i == s.size() or j == t.size())
    //         return 0;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     if (s[i] == t[j]) {
    //         return dp[i][j] = 1 + f(s, t, i + 1, j + 1);
    //     }
    //     return dp[i][j] = max(f(s, t, i + 1, j), f(s, t, i, j + 1));
    // }
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // for(int i = 0; i <= m; i++) dp[0][i] = 0;
        // for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};