class Solution {
public:
    int ans, cnt = 0;
    void f(TreeNode* root, int k){
        if(root == NULL) return;
        kthSmallest(root->left, k);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }  
        kthSmallest(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        f(root, k);
        return ans;
    }
};