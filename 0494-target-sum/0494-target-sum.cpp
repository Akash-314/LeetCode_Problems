class Solution {
public:
    unordered_map<long long, int> dp[21];
    int f(vector<int>& nums, int t, int i) {
        if (i < 0)
            return t == 0;
        if (dp[i].count(t))
            return dp[i][t];
        int way1 = f(nums, t + nums[i], i - 1);
        int way2 = f(nums, t - nums[i], i - 1);

        return dp[i][t] = way1 + way2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return f(nums, target, n - 1);
    }
};