class Solution {
public:
    int dp[101][2][101];
    int f(vector<int>& pre, int i, int m, bool turn){
        int n = pre.size();
        if(dp[i][turn][m] != -1) return dp[i][turn][m]; 
        if(i >= n) return 0;
        int ans = 0;
        int x = 2*m;
        if(turn){
            ans = -1e9;
            int a = 0;
            for(int j = i; j < min(i+x, n); j++){
                if(i-1 >= 0) a = pre[j] - pre[i-1];
                else a = pre[j];
                ans = max(ans, a + f(pre, j+1, max(m, j-i+1), false));
            }
        }else{
            ans = 1e9;
            int a = 0;
            for(int j = i; j < min(i+x, n); j++){
                if(i-1 >= 0) a = pre[j] - pre[i-1];
                else a = pre[j];
                ans =  min(ans, -a + f(pre, j+1, max(m, j-i+1), true));
        }
      }
        return dp[i][turn][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> pre(n);
        memset(dp, -1, sizeof dp);
        pre[0] = piles[0];
        for(int i = 1; i < n; i++){
            pre[i] = piles[i] + pre[i-1];
        }
        int diff = f(pre, 0, 1, true);
        return (pre.back() + diff) / 2;
    }
};