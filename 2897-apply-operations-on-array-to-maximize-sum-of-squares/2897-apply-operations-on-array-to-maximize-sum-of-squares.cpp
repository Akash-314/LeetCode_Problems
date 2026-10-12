class Solution {
public:
    int mod = 1e9 + 7;
    #define ll long long
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(32, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j)) { // to find set bit
                    cnt[j]++;
                }
            }
        }
        ll ans = 0;
        while (k--) {
            ll curr = 0;
            for (int i = 0; i < 32; i++) {
                if (cnt[i] > 0) {
                    curr = curr | (1 << i); // to set the bit
                    cnt[i]--;
                }
            }
            ans = (ans + (curr * curr)) % mod;
        }
        return ans;
    }
};