class Solution {
public:
    bool find(TreeNode* root, TreeNode* t){
        if(root==NULL) return false;
        if(root==t) return true;
        return find(root->left,t) || find(root->right,t);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(find(root->left,p) && find(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else if(find(root->right,p) && find(root->right,q)) return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};