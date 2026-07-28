class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        pre[0] = nums[0];
        suf[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], nums[i - 1]);
            suf[n - i - 1] = min(suf[n - i], nums[n - i]);
        }
        for (int i = 0; i < n; i++) {
            if (pre[i] <= suf[i]) {
                return i+1;
            }
        }
        return -1;
    }
};