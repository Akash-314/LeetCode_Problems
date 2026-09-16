class Solution {
public:
    int n;
    int dp[2001];
    bool isPal(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int f(string& s, int i) {
        if (i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for (int j = i; j < n; j++) {
            if (isPal(s, i, j)) {
                ans = min(ans, 1 + f(s, j + 1));
            }
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return f(s, 0) - 1;
    }
};