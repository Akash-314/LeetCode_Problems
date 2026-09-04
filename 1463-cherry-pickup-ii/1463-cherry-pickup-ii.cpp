class Solution {
public:
    int m, n;
    int dp[71][71][71];
    int f(vector<vector<int>>& grid, int i, int j1, int j2) {
        if (j1 >= n || j2 >= n || j1 < 0 || j2 < 0)
            return -1e8;
        if (i == m - 1) {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int maxi = 0;
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                int val = 0;
                if (j1 == j2)
                    val = grid[i][j1];
                else {
                    val = grid[i][j1] + grid[i][j2];
                }
                val += f(grid, i + 1, j1 + x, j2 + y);
                maxi = max(maxi, val);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return f(grid, 0, 0, n - 1);
    }
};