class Solution {
public:
#define ll long long
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        ll sum = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            sum += (nums[j] * nums[j]);
            sum -= (nums[i] * nums[i]);
            i++;
            j--;
        }
        if (n & 1)
            sum += (nums[j] * nums[j]);
        return sum;
    }
};