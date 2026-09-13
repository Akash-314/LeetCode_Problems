class Solution {
public:
    int dp[100001];
    int f(int n){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = 1e9;
        int sum = 0;
        int i = 1;
        while(true){
            sum += i;
            if(sum > n) break;

            ans = min(ans, f(n - sum) + i + 1);
            i++;
        }
        return dp[n] = ans;
    }
    int minDays(int n) {
        memset(dp, -1, sizeof(dp));
        return f(n) - 1;
    }
};