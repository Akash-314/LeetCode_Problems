class Solution {
public:
    // int f(vector<int>& pre, int i) {
    //     int n = pre.size();
    //     if (i == n - 1) return pre[n - 1];
    //     if(dp[i] != -1) return dp[i];
    //     int take = pre[i] - f(pre, i + 1);
    //     int skip = f(pre, i + 1);
    //     return dp[i] = max(take, skip);
    // }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pre(n);
        vector<int> dp(n);
        pre[0] = stones[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + stones[i];
        }
        dp[n - 1] = pre[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            int take = pre[i] - dp[i + 1];
            int skip = dp[i + 1];
            dp[i] = max(take, skip);
        }
        return dp[1];
    }
};