class Solution {
public:
    int dp[30001][2];
    int f(vector<int>& a, int i, bool buy){
        if(i == a.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy){
            profit = max(-a[i] + f(a, i+1, 0),f(a, i+1, 1));
        }else{
             profit = max(a[i] + f(a, i+1, 1), f(a, i+1, 0));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return f(prices, 0, 1);
    }
};