class Solution {
public:
    int f(TreeNode* root, int &mx){
        if(root == NULL) return 0;
        int left = max(0, f(root->left, mx));
        int right = max(0, f(root->right, mx));

        mx = max(mx, left+right+root->val);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        f(root, mx);
        return mx;
    }
};