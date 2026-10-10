class Solution {
public:
#define ll long long
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<ll> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }
        sort(diff.rbegin(), diff.rend());

        ll l = 0, r = 1e14;
        ll lim = 0;
        auto check = [&](ll mid) {
            ll curr = k1 + k2;
            for (int i = 0; i < n; i++) {
                ll val = abs(nums1[i] - nums2[i]) - mid;
                if (val > 0)
                    curr -= val;
                if (curr < 0)
                    break;
            }
            if (curr < 0)
                return false;
            else
                return true;
        };
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (check(mid)) {
                r = mid - 1;
                lim = mid;
            } else
                l = mid + 1;
        }

        ll k = k1 + k2;
        for (int i = 0; i < n; i++) {
            ll val = diff[i] - lim;
            if (val > 0) {
                diff[i] -= val;
                k -= val;
            }
            if (k <= 0)
                break;
        }
        for (int i = 0; i < n; i++) {
            if (k <= 0)
                break;
            else {
                if (abs(diff[i] - 1) < diff[i]) {
                    diff[i] = abs(diff[i] - 1);
                    k--;
                } else
                    break;
            }
        }
        ll res = 0;
        for (int i = 0; i < n; i++) {
            res += diff[i] * diff[i];
        }
        return res;
    }
};