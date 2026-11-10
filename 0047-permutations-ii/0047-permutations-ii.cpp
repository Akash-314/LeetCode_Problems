class Solution {
public:
    set<vector<int>> st;
    void f(vector<int>& nums, int i, vector<int>& v, vector<bool>& vis) {
        if (v.size() == nums.size()) {
            st.insert(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i])
                continue;
            vis[i] = true;
            v.push_back(nums[i]);
            f(nums, i + 1, v, vis);
            v.pop_back();
            vis[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        vector<bool> vis(n, false);
        f(nums, 0, v, vis);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};