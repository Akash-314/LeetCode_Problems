class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = 1;
            for (int j = i; j < n; j++) {
                l = lcm(nums[j], l);
                // cout << l << " ";
                if (l == k)
                    ans++;
                if (l > k)
                    break;
            }
        }
        return ans;
    }
};