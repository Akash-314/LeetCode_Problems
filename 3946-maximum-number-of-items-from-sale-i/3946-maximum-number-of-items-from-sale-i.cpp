class Solution {
public:
    int m, mn;
    vector<int> free;
    vector<vector<int>> dp;
    int f(int i, int b, vector<vector<int>>& items) {
        if (i == m)
            return b / mn;
        if (dp[i][b] != -1)
            return dp[i][b];
        int ans = f(i + 1, b, items);
        if (items[i][1] <= b) {
            ans = max(ans, 1 + free[i] + f(i + 1, b - items[i][1], items));
        }
        return dp[i][b] = ans;
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        m = items.size();
        free.assign(m, 0);
        mn = INT_MAX;
        for (int i = 0; i < m; i++) {
            mn = min(mn, items[i][1]);
            for (int j = 0; j < m; j++) {
                if (i != j && items[j][0] % items[i][0] == 0)
                    free[i]++;
            }
        }
        int ans = 0;
        dp.assign(m, vector<int>(budget + 1, -1));
        return f(0, budget, items);
    }
};