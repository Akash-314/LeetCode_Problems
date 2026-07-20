class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        vector<int> v;
        int a = 0, b = 0;
        int total = m * n;
        k %= total;

        int pos = k;
        a = pos / n;
        b = pos % n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v.push_back(grid[i][j]);
            }
        }
        int x = 0;
        for (int i = a; i < m; i++) {
            for (int j = b; j < n; j++) {
                ans[i][j] = v[x];
                x++;
            }
            b = 0;
        }
        int i = 0, j = 0;
        while (x < v.size()) {
            ans[i][j] = v[x++];
            if (j == n - 1) {
                i++;
                j = 0;
            } else
                j++;
        }
        return ans;
    }
};