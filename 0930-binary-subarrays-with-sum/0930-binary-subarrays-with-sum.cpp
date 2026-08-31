class Solution {
public:
    int f(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int n = nums.size();
        int l = 0;
        int ans = 0, cnt = 0;
        for (int r = 0; r < n; r++) {
            ans += nums[r];
            while (ans > goal) {
                ans -= nums[l];
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums, goal) - f(nums, goal - 1);
    }
};