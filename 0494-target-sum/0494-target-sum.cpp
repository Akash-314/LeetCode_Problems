class Solution {
public:
    int dp[21][5002];
    // unordered_map<int,unordered_map<long long, int>> dp;
    int f(vector<int>& nums, int t, int i) {
        if (i < 0)
            return t == 0;
        if (dp[i][t + 2000] != -1)
            return dp[i][t + 2000];
        int way1 = f(nums, t + nums[i], i - 1);
        int way2 = f(nums, t - nums[i], i - 1);

        return dp[i][t + 2000] = way1 + way2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return f(nums, target, n - 1);
    }
};