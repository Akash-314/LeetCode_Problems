class Solution {
public:
    int dp[50001][2];
    int stone(vector<int>& v, int i, bool turn) {
        int n = v.size();
        if(i >= n) return 0;
        if(dp[i][turn] != -1) return dp[i][turn];
        int ans = 0;
        if(turn){
            ans = -1e9;
            ans = max(ans, v[i] + stone(v, i+1, false));
            if(i+1 < n) ans = max(ans, v[i] + v[i+1] + stone(v, i+2, false));
            if(i+2 < n) ans = max(ans, v[i] + v[i+1] + v[i+2] + stone(v, i+3, false));
        }else{
            ans = 1e9;
            ans = min(ans, -v[i] + stone(v, i+1, !false));
            if(i+1 < n) ans = min(ans, -v[i] - v[i+1] + stone(v, i+2, !false));
            if(i+2 < n) ans = min(ans, -v[i] - v[i+1] - v[i+2] + stone(v, i+3, !false));
        }
        return dp[i][turn] = ans;
    }
    string stoneGameIII(vector<int>& st) {
        memset(dp, -1, sizeof dp);
        int ans = stone(st, 0, true);
        if(ans > 0) return "Alice";
        else if(ans < 0) return "Bob";
        else return "Tie";
    }
};