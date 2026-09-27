class Solution {
public:
#define ll long long
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        // ll sum = 0;
        // for(int i = 0; i < n; i++) {
        //     if(i & 1) sum -= nums[i];
        //     else sum += nums[i];
        // }
        // ll ans = sum;
        ll temp = 0;
        vector<ll> b(n);
        for (int i = 0; i < n; i++) {
            temp += (i & 1) ? -1LL * nums[i] : nums[i];
        }
        if(n < 2) return temp;
        // for (int i = 0; i < n; i++) {
        //     b[i] = (i & 1) ? -1LL * nums[i] : nums[i];
        // }
        ll pref = 0, mnSum = LLONG_MAX;
        ll mx[2] = {0, LLONG_MIN / 4};
        for (int i = 1; i <= n; i++) {
            ll x;
            int idx = i-1;
            if(idx & 1) x = -(ll)nums[idx];
            else x = (ll)nums[idx];
            pref += x;
            int p = i & 1;
            if (mx[p] != LLONG_MIN / 4) mnSum = min(mnSum, pref - mx[p]);
            mx[p] = max(mx[p], pref);
        }
        return max(temp, temp - 2LL * mnSum);
    }
};