class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 or j == 0 or j == n - 1 or i == m - 1) and
                    grid[i][j] == 1) {
                    grid[i][j] = -1;
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (!q.empty()) {
            auto cell = q.front();
            int r = cell.first;
            int c = cell.second;
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];
                if (nr < 0 or nc < 0 or nr >= m or nc >= n or
                    grid[nr][nc] != 1) {
                    continue;
                }
                grid[nr][nc] = -1;
                q.push({nr, nc});
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};