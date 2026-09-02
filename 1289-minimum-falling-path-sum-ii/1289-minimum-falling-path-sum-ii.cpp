class Solution {
public:
    int dp[201][201];
    bool vis[201][201];
    int f(vector<vector<int>>& mat, int i, int j) {
        if (j < 0 || j >= mat.size())
            return INT_MAX;
        if (i == mat.size() - 1)
            return mat[i][j];
        if (vis[i][j])
            return dp[i][j];

        vis[i][j] = true;
        int ans = 1e9;
        for (int k = 0; k < mat.size(); k++) {
            if (k == j)
                continue;
            ans = min(ans, f(mat, i + 1, k));
        }
        return dp[i][j] = mat[i][j] + ans;
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = INT_MAX;
        memset(vis, false, sizeof vis);
        for (int j = 0; j < n; j++) {
            ans = min(ans, f(mat, 0, j));
        }
        return ans;
    }
};