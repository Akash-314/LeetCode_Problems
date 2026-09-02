class Solution {
public:
    // int dp[201][201];
    // int f(vector<vector<int>>& t, int i, int j, int m) {
    //     int n = t[i].size();
    //     if (i == m-1)
    //         return t[i][j];
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int ans = 1e9;
    //     ans = min(ans, f(t, i + 1, j, m));
    //     ans = min(ans, f(t, i + 1, j + 1, m));
    //     return dp[i][j] = ans + t[i][j];
    // }
    int minimumTotal(vector<vector<int>>& t) {
        int m = t.size();
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < t[i].size(); j++) {
                t[i][j] += min(t[i + 1][j], t[i + 1][j + 1]);
            }
        }
        return t[0][0];
    }
};