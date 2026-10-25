class Solution {
public:
#define ll long long
    ll f(ll n) {
        string s = to_string(n);
        sort(s.rbegin(), s.rend());
        return stoll(s);
    }

    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<ll, ll>> a;
        ll ans = 0;

        for (int x : nums) {
            ll mx = f(x);
            ans += x;
            a.push_back({mx - x, mx});
        }
        sort(a.rbegin(), a.rend());
        for (int i = 0; i < n && k > 0; i++) {
            if (a[i].first > 0) {
                ans += a[i].first;
                k--;
            }
        }
        return ans;
    }
};