class Solution {
public:
    unordered_map<int, int> mp;
    int mx = 0;
    int f(TreeNode* root) {
        if (!root)
            return 0;
        int sum = 0;
        sum = root->val + f(root->left) + f(root->right);
        mp[sum]++;
        mx = max(mx, mp[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        f(root);
        for (auto x : mp) {
            if (x.second == mx)
                ans.push_back(x.first);
        }
        return ans;
    }
};