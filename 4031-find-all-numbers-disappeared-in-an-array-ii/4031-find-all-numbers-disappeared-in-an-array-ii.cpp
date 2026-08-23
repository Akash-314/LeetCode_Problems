class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        vector<vector<int>> ans;
        int l = -1, u = -1;
        for (int i = lower; i <= upper; i++) {
            if (!st.count(i)) {
                if (l == -1) {
                    l = i;
                }
                u = i;
            } else {
                if (l != -1) {
                    ans.push_back({l, u});
                    l = -1, u = -1;
                }
            }
        }
        if (l != -1)
            ans.push_back({l, u});
        return ans;
    }
};