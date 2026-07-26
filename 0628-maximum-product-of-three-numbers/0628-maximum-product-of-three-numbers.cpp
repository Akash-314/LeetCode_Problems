class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n1 = -1000, n2 = -2000, n3 = -3000, m1 = 1000, m2 = 2000;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] >= n1) {
                n3 = n2;
                n2 = n1;
                n1 = nums[i];
            } else if (nums[i] >= n2) {
                n3 = n2;
                n2 = nums[i];
            } else {
                n3 = max(nums[i], n3);
            }

            if (nums[i] <= m1) {
                m2 = m1;
                m1 = nums[i];
            } else
                m2 = min(m2, nums[i]);
        }
        return max(1LL * n1 * n2 * n3, 1LL * n1 * m1 * m2);
    }
};