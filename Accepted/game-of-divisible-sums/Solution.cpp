class Solution {
public:
#define ll long long
    vector<vector<ll>> dp;
    ll f(int i, int turn, vector<int>& nums) {
        int n = nums.size();

        if (i == n)
            return 0;
        if(dp[i][turn] != LLONG_MIN) return dp[i][turn];
        ll sum = nums[i];
        int nxt = turn;
        if (sum % 3 == 0)
            nxt = 1 - turn;
        ll a = (turn == 0 ? sum : -sum) + f(i + 1, nxt, nums);
        ll ans = a;
        if (i + 1 < n) {
            sum += nums[i + 1];
            nxt = turn;
            if (sum % 3 == 0)
                nxt = 1 - turn;

            ll b = (turn == 0 ? sum : -sum) + f(i + 2, nxt, nums);

            if (turn == 0)
                ans = max(ans, b);
            else
                ans = min(ans, b);
        }
        return dp[i][turn] = ans;
    }
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<ll>(2, LLONG_MIN));
        return f(0, 0, nums);
    }
};