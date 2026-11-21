class Solution {
public:
    void dfs(int curr, vector<int>& parent, vector<int>& last, vector<int>& ans,
             string& s, vector<vector<int>>& ch) {
        int c = s[curr] - 'a';
        int near = last[c];

        last[c] = curr;
        for (int neigh : ch[curr]) {
            dfs(neigh, parent, last, ans, s, ch);
        }
        last[c] = near;
        if (curr != 0) {
            int np = parent[curr];
            if (near != -1) {
                np = near;
            }
            parent[curr] = np;
            ans[np] += ans[curr];
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> ch(n);
        for (int i = 1; i < n; i++) {
            int x = parent[i];
            ch[x].push_back(i);
        }
        vector<int> ans(n, 1);
        vector<int> last(26, -1);
        dfs(0, parent, last, ans, s, ch);
        return ans;
    }
};