class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        vector<int> pre(n, 0);
        pre[0] = cp[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + cp[i];
        if (n == k)
            return pre[n - 1];
        int ans = 0, sw = INT_MAX;
        int len = n - k;
        int sum;
        for (int i = 0; i + len - 1 < n; i++) {
            if (i == 0)
                sum = pre[i + len - 1];
            else
                sum = pre[i + len - 1] - pre[i - 1];
            sw = min(sw, sum);
        }
        ans = pre[n - 1] - sw;
        return ans;
    }
};