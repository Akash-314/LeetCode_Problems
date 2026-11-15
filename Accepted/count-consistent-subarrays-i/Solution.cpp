class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = -1;
        int mn = INT_MAX;
            for (int j = i; j < n; j++) {
                x &= nums[j];
                mn = min(mn, nums[j]);
                if (x == mn)
                    ans++;
            }
        }
        return ans;
    }
};