class Solution {
public:
    int dp[201][20001];
    int f(int idx, int target, vector<int>& nums) {
        if (target == 0)
            return true;
        if (idx == 0)
            return (target == nums[idx]);

        if (dp[idx][target] != -1)
            return dp[idx][target];
        bool notTake = f(idx - 1, target, nums);
        bool take = false;
        if (nums[idx] <= target) {
            take = f(idx - 1, target - nums[idx], nums);
        }
        return dp[idx][target] = take or notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        memset(dp, -1, sizeof(dp));
        if (sum % 2 == 1)
            return false;
        return f(n - 1, sum / 2, nums);
    }
};