class Solution {
public:
    #define ll long long
    vector<ll> dp;
    ll f(int i, vector<vector<int>>& adj, vector<int>& op, vector<int>& scr) {
        ll sum = 0, mn = LLONG_MAX;
        if (dp[i] != -1e9)
            return dp[i];
        for (ll j : adj[i]) {
            ll x = f(j, adj, op, scr);
            sum += x;
            mn = min(mn, x);
        }

        if (!adj[i].empty()) {
            if (op[i] == 1)
                sum -= mn;
            else if (mn < 0)
                sum -= mn;
        }
        return dp[i] = scr[i] + sum;
    }
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        dp.assign(n, -(ll)1e9);
        return f(0, adj, op, score);
    }
};