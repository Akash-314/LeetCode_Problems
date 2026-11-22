class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        int i = 0, j = 0;
        while (i < n) {
            j = i;
            while (j + 1 < n and nums[j] == nums[j + 1])
                j++;
            if (i <= n - 2 and j >= 1) {
                mp[nums[j]] = max(mp[nums[j]], j - i + 1);
            }
            i = j + 1;
        }
        long long ans = LLONG_MAX;
        for (auto x : mp) {
            long long a = 1LL * x.first * (n - x.second);
            ans = min(ans, a);
        }
        return ans;
    }
};