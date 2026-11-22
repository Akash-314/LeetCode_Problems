class Solution {
public:
    int dp1[202][202][102];
    int f3(string& s, int start, int end, int d) {
        if (dp1[start][end][d] != -1)
            return dp1[start][end][d];
        int N = end - start + 1;
        int cost = 0;
        for (int i = 0; i < d; i++) {
            string tt;
            for (int j = i; j < N; j += d) {
                tt.push_back(s[start + j]);
            }
            int a = 0, b = tt.size() - 1;
            while (a < b) {
                if (tt[a] != tt[b]) {
                    cost++;
                }
                a++;
                b--;
            }
        }
        return dp1[start][end][d] = cost;
    }
    int f2(string& s, int start, int end) {
        int N = end - start + 1;
        if (N == 1)
            return 1e5;
        int ans = 1e6;
        for (int i = 1; i * i <= N; i++) {
            if (N % i == 0) {
                ans = min(ans, f3(s, start, end, i));
                if (i != 1) {
                    ans = min(ans, f3(s, start, end, N / i));
                }
            }
        }
        return ans;
    }

    int dp[202][202][102];
    int f(string& s, int k, int i, int lst) {
        if (k == 1)
            return f2(s, lst, s.size() - 1);
        if (i == s.size() - 1 && k > 1)
            return 1e6;

        if (dp[i][lst][k] != -1)
            return dp[i][lst][k];
        int ans = 1e9;
        ans = min(ans, f(s, k, i + 1, lst));
        ans = min(ans, f2(s, lst, i) +
                           f(s, k - 1, min((int)s.size() - 1, i + 2), i + 1));

        return dp[i][lst][k] = ans;
    }

    int minimumChanges(string s, int k) {
        memset(dp, -1, sizeof(dp));
        memset(dp1, -1, sizeof(dp));
        return f(s, k, min((int)s.size() - 1, 1), 0);
    }
};