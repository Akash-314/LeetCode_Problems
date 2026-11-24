class Solution {
public:
#define ll long long
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ll pro = 1;
            ll lc = 1, gc = 0;
            for (int j = i; j < n; j++) {
                if (pro > 1e8)
                    break;
                pro *= 1LL * nums[j];
                lc = lcm(lc, (ll)nums[j]);
                gc = __gcd(gc, (ll)nums[j]);
                if (pro == lc * gc) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};