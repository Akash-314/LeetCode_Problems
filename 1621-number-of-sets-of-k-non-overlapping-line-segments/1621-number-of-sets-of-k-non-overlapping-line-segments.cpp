class Solution {
public:
    int m = 1e9 + 7;
#define ll long long
    // int f(int n, int k, int i){
    //     if(i >= n) return 0;
    //     if(k == 0) return 1;
    //     int take = 0;
    //     for(int j = i+1; j <= n-1; j++){
    //         take += f(n, k-1, j);
    //     }
    //     int skip = f(n, k, i+1) % m;
    //     return take + skip;
    // }
    int numberOfSets(int n, int k) {
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
        vector<ll> prev(n + 1);
        for (int i = 0; i < n; i++) dp[i][0] = 1;
        for (int K = 1; K <= k; K++) {
            for (int x = n - 1; x >= 0; x--) {
                prev[x] = (prev[x + 1] + dp[x][K - 1]) % m;
            }
            for (int i = n - 1; i >= 0; i--) {
                ll take = prev[i + 1];
                ll skip = dp[i + 1][K] % m;
                dp[i][K] = (skip + take) % m;
            }
        }
        return dp[0][k];
    }
};