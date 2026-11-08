class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }
        int ans = 0;
        while (!q.empty()) {
            auto cell = q.front();
            int r = cell.first;
            int c = cell.second;
            q.pop();
            for (int j = 0; j < n; j++) {
                if (j == c)
                    continue;
                if (grid[r][j] == 1) {
                    ans++;
                    grid[r][j] = -1;
                }
            }
            for (int j = 0; j < m; j++) {
                if (j == r)
                    continue;
                if (grid[j][c] == 1) {
                    ans++;
                    grid[j][c] = -1;
                }
            }
        }
        return ans;
    }
};