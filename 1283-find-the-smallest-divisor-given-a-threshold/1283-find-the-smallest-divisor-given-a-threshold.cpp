class Solution {
public:
#define ll long long
    bool f(vector<int>& nums, int t, int div) {
        int n = nums.size();
        ll res = 0;
        for (int i = 0; i < n; i++) {
            res += (nums[i] + div - 1) / div;
            // ceil(a/b) = (a + b - 1) / b;
        }
        return res <= t;
    }
    int smallestDivisor(vector<int>& nums, int t) {
        int n = nums.size();
        int l = 1, r = *max_element(nums.begin(), nums.end());
        int ans = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (f(nums, t, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};