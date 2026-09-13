class Solution {
public:
    int n;
    int cntOv(vector<vector<int>>& a, vector<vector<int>>& b, int row, int col) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int bi = row + i;
                int bj = col + j;
                if (bi < 0 || bi >= n || bj < 0 || bj >= n)
                    continue;
                if (a[i][j] == 1 and b[bi][bj] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        n = img1.size();
        int ans = 0;
        for (int i = -n + 1; i < n; i++) {
            for (int j = -n + 1; j < n; j++) {
                ans = max(ans, cntOv(img1, img2, i, j));
            }
        }
        return ans;
    }
};