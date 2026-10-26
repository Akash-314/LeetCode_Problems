class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        int temp = INT_MAX;
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if (abs(target - sum) < abs(target - ans)) {
                    ans = sum;
                }
                if (target == ans)
                    return ans;
                if (sum < target)
                    l++;
                else if (sum > target)
                    r--;
            }
        }
        return ans;
    }
};