class Solution {
public:
#define ll long long
    int f(vector<int>& nums, int page) {
        int st = 1;
        ll res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] + res <= page) {
                res += nums[i];
            } else {
                st++;
                res = nums[i];
            }
        }
        return st;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *max_element(nums.begin(), nums.end());
        int r = 1e9;

        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (f(nums, mid) > k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};