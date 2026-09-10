/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* parent) {
        if(root == NULL) return NULL;
        if (root == p || root == q)
            return root;
        TreeNode* left = f(root->left, p, q, root);
        TreeNode* right = f(root->right, p, q, root);
         if (left && right)
            return root;

        if (left)
            return left;

        if (right)
            return right;

        return NULL;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return f(root, p, q, NULL);

    }
};