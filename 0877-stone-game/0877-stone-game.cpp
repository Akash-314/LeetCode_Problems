class Solution {
public:
    int dp[501][501];
    int stone(vector<int>& piles, int i, int j) {
        if(i == j) return piles[i];
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max(piles[i] - stone(piles, i+1, j), piles[j] - stone(piles, i, j-1));
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof dp);
        return (stone(piles, 0, n - 1) > 0);
    }
};