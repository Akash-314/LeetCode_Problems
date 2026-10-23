class Solution {
public:
    int f(int n, int i, vector<int>& costs, vector<int>& dp) {
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        if (i + 1 <= n)
            ans = min(ans, costs[i] + 1 + f(n, i + 1, costs, dp));

        if (i + 2 <= n)
            ans = min(ans, costs[i + 1] + 4 + f(n, i + 2, costs, dp));

        if (i + 3 <= n)
            ans = min(ans, costs[i + 2] + 9 + f(n, i + 3, costs, dp));

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        return f(n, 0, costs, dp);
    }
};