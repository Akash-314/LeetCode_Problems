class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> conn(n);
        vector<bool> ans(q);
        int a = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff)
                a++;
            conn[i] = a;
        }
        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            if (conn[u] == conn[v])
                ans[i] = true;
            else
                ans[i] = false;
        }
        return ans;
    }
};