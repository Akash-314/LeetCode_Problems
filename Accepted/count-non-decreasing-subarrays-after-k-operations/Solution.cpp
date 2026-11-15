class Solution {
public:
#define ll long long
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, int>> dq;
        ll s = 0, ans = 0;
        int j = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            int cnt = 1;
            while (!dq.empty() && dq.back().first < nums[i]) {
                s += 1LL * (nums[i] - dq.back().first) * dq.back().second;
                cnt += dq.back().second;
                dq.pop_back();
            }
            dq.push_back({nums[i], cnt});
            while (s > k) {
                s -= dq.front().first - nums[j];
                if (dq.front().second == 1) {
                    dq.pop_front();
                } else {
                    dq.front().second--;
                }
                j--;
            }
            ans += j - i + 1;
        }
        return ans;
    }
};