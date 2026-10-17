class Solution {
public:
    int sum(int n) {
        int s = 0;
        while (n > 0) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> a = nums;
        sort(a.begin(), a.end(), [&](int x, int y) {
            if (sum(x) == sum(y))
                return x < y;
            return sum(x) < sum(y);
        });
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[a[i]] = i;

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || mp[nums[i]] == i)
                continue;
            int j = i, cnt = 0;
            while (!vis[j]) {
                vis[j] = true;
                j = mp[nums[j]];
                cnt++;
            }
            ans += cnt - 1;
        }
        return ans;
    }
};