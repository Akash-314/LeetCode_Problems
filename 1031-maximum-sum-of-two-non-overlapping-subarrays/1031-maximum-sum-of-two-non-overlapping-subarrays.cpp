class Solution {
public:
#define ll long long
    int f(vector<int>& pre, int L, int M) {
        int res = 0, lMx = 0, n = pre.size();
        for (int mEnd = L + M - 1; mEnd < n; mEnd++) {
            int lEnd = mEnd - M;
            int lStart = lEnd - L;

            int mSum = pre[mEnd] - pre[lEnd];
            int lSum = pre[lEnd] - (lStart < 0 ? 0 : pre[lStart]);

            lMx = max(lMx, lSum);
            res = max(res, lMx + mSum);
        }
        return res;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        return max(f(pre, firstLen, secondLen), f(pre, secondLen, firstLen));
    }
};