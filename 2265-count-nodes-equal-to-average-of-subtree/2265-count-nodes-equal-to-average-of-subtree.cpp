class Solution {
public:
    int ans = 0;
    int cnt(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + cnt(root->left) + cnt(root->right);
    }
    int f(TreeNode* root) {
        if (!root)
            return 0;
        int left = f(root->left);
        int right = f(root->right);
        int nc = cnt(root);
        int sum = left + right + root->val;
        if (sum / nc == root->val)
            ans++;
        return sum;
    }
    int averageOfSubtree(TreeNode* root) {
        f(root);
        return ans;
    }
};