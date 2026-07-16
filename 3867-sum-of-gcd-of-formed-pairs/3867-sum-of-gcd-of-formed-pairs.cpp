class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        vector<long long> mx(nums.size());
        vector<long long> prefixGcd(nums.size());
        mx[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            mx[i] = max(mx[i - 1], (long long)nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            prefixGcd[i] = gcd(nums[i], mx[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int i = 0;
        int j = prefixGcd.size() - 1;
        long long ans = 0;
        while (i < j) {
            ans += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return ans;
    }
};