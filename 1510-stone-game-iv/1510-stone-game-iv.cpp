class Solution {
public:
    int dp[100001];
    bool f(int n) {
        if (n == 0) return false;
        if (dp[n] != -1)
            return dp[n];
            bool ans = false;
            for (int i = 1; i * i <= n; i++) {
                int sqr = i*i;
                if(!f(n - sqr)) return dp[n] = true;
            }
        return dp[n] = false;
    }
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof dp);
        return f(n);
    }
};