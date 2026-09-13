class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> temp(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                temp[i][j] = grid[i][(j + rowShift[i]) % n];
            }
        }
        vector<vector<int>>ans(n, vector<int>(n));
        for(int j = 0; j < n; j++){
            for(int i = 0; i < n; i++){
                ans[i][j] = temp[(i + colShift[j]) % n][j];
            }
        }
        return ans;
    }
};