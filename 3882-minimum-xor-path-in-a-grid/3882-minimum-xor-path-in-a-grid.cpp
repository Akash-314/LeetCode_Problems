class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int f(vector<vector<int>>& grid, int i, int j, int xr) {
        xr ^= grid[i][j];

        if (dp[i][j][xr] != -1)
            return dp[i][j][xr];

        if (i == m - 1 && j == n - 1)
            return dp[i][j][xr] = xr;

        int res = INT_MAX;

        if (i + 1 < m)
            res = min(res, f(grid, i + 1, j, xr));

        if (j + 1 < n)
            res = min(res, f(grid, i, j + 1, xr));

        return dp[i][j][xr] = res;
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(
            n, vector<int>(1024, -1)
        ));

        return f(grid, 0, 0, 0);
    }
};