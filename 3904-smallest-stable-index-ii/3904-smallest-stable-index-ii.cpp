class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int n = nums.size();
        int instable;
        vector<int> mx(n);
        vector<int> mn(n);
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            mx[i] = maxi;
        }
        for (int i = n - 1; i >= 0; i--) {
            mini = min(mini, nums[i]);
            mn[i] = mini;
        }
        for (int i = 0; i < n; i++) {
            instable = mx[i] - mn[i];
            if (instable <= k)
                return i;
        }
        return -1;
    }
};