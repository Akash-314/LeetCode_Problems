class Solution {
public:
    int ans = 0;
    pair<int, int> f(TreeNode* root) {
        if (!root)
            return {0, 0};
        auto [lSum, lCnt] = f(root->left);
        auto [RSum, RCnt] = f(root->right);
        int sum = lSum + RSum + root->val;
        int cnt = 1 + lCnt + RCnt;
        if (sum / cnt == root->val)
            ans++;
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        f(root);
        return ans;
    }
};