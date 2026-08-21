class Solution {
public:
    int f(vector<int>& a, int d, int k) {
        int n = a.size();
        int cnt = 0;
        int nob = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= d) {
                cnt++;
            } else {
                nob += (cnt / k);
                cnt = 0;
            }
        }
        nob += (cnt / k);
        return nob;
    }
    int minDays(vector<int>& a, int m, int k) {
        int n = a.size();
        long long val = 1LL * m * 1LL * k;
        if (val > n)
            return -1;
        int l = *min_element(a.begin(), a.end());
        int r = *max_element(a.begin(), a.end());
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (f(a, mid, k) >= m) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};