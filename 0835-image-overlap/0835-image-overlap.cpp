class Solution {
public:
    int n;
    int countOverlap(vector<vector<int>>& a, vector<vector<int>>& b, int rowOffset, int colOffset) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int bi = rowOffset + i;
                int bj = colOffset + j;
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
        int maxOverlap = 0;
        for (int i = -n + 1; i < n; i++) {
            for (int j = -n + 1; j < n; j++) {
                maxOverlap = max(maxOverlap, countOverlap(img1, img2, i, j));
            }
        }
        return maxOverlap;
    }
};