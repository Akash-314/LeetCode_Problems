class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int r = 0, c = 0;
        vis[r][c] = true;
        while (true) {
            int nr = r, nc = c;
            char dir = grid[r][c];
            if (dir == 'L')
                nc--;
            else if (dir == 'R')
                nc++;
            else if (dir == 'U')
                nr--;
            else if (dir == 'D')
                nr++;
            if (nr < 0 or nc < 0 or nr >= m or nc >= n or vis[nr][nc])
                break;
            vis[nr][nc] = true;
            r = nr;
            c = nc;
        }
        return {r, c};
    }
};