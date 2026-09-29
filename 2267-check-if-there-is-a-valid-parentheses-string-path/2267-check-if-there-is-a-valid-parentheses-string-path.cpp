class Solution {
public:
    int dp[101][101][202];
    bool ans;
    bool f(vector<vector<char>>& grid, int i, int j, int cnt) {
        if (i >= grid.size() or j >= grid[0].size() or cnt < 0)
            return false;
        if (grid[i][j] == '(') cnt++;
        else cnt--;
        if (cnt < 0) return false;
        if (i == grid.size() - 1 and j == grid[0].size() - 1)
            return cnt == 0;
        if (dp[i][j][cnt] != -1)
            return dp[i][j][cnt];
        ans = f(grid, i + 1, j, cnt) || f(grid, i, j + 1, cnt);
        return dp[i][j][cnt] = ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp, -1, sizeof(dp));
        return f(grid, 0, 0, 0);
    }
};