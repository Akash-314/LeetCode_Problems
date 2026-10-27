class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int i = 0, j = 0;
        vector<int> ans;
        int cnt = m * n;

        int a = 0, b = m - 1;
        int c = 0, d = n - 1;

        while (cnt > 0) {
            for (j = c; j <= d && cnt > 0; j++) {
                ans.push_back(mat[a][j]);
                cnt--;
            }
            a++;

            for (i = a; i <= b && cnt > 0; i++) {
                ans.push_back(mat[i][d]);
                cnt--;
            }
            d--;

            for (j = d; j >= c && cnt > 0; j--) {
                ans.push_back(mat[b][j]);
                cnt--;
            }
            b--;

            for (i = b; i >= a && cnt > 0; i--) {
                ans.push_back(mat[i][c]);
                cnt--;
            }
            c++;
        }

        return ans;
    }
};