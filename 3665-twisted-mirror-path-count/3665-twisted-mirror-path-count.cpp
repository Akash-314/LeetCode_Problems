class Solution {
public:
    int m, n;
    int dp[501][501][2];
    int mod = 1e9 + 7;
    int f(vector<vector<int>>& grid, int i, int j, int cf) {
        if (i == m - 1 and j == n - 1)
            return 1;
        if (i >= m or j >= n)
            return 0;
        int ans = 0;
        if (dp[i][j][cf] != -1)
            return dp[i][j][cf];
        if (grid[i][j] == 1) {
            if (cf == 1) {
                ans += f(grid, i + 1, j, 0);
            } else {
                ans += f(grid, i, j + 1, 1);
            }
        } else {
            ans += f(grid, i + 1, j, 0);
            ans += f(grid, i, j + 1, 1);
        }
        return dp[i][j][cf] = ans % mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return f(grid, 0, 0, 0);
    }
};