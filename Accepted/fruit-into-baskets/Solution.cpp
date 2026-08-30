class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for (int r = 0; r < n; r++) {
            mp[nums[r]]++;
            while (mp.size() > 2) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};