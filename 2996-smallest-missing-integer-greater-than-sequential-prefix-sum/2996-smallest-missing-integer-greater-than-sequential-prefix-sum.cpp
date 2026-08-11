class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        sum += nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else
                break;
        }
        for (int i = sum; i < 1e9; i++) {
            if (!st.count(i)) {
                return i;
            }
        }
        return 0;
    }
};