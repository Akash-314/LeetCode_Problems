class Solution {
public:
    bool can(vector<int>& pos, int m, int d) {
        int cnt = 1;
        int last = pos[0];
        for (int i = 1; i < pos.size(); i++) {
            if (pos[i] - last >= d) {
                cnt++;
                last = pos[i];
                if (cnt == m)
                    return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& pos, int m) {
        int n = pos.size();
        sort(pos.begin(), pos.end());
        int l = 1, r = pos[n - 1] - pos[0];
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (can(pos, m, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};