class Solution {
public:
    // int gcd(int a, int b) {
    //     if (b == 0)
    //         return a;
    //     return gcd(b, a % b);
    // }
    int findGCD(vector<int>& nums) {
        int ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ans = __gcd(nums[0], nums[n - 1]);
        // ans = gcd(nums[0], nums[n - 1]);
        return ans;
    }
};