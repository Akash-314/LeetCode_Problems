class Solution {
public:
    TreeNode* build(int is, int ie, vector<int>& inorder, int ps, int pe, vector<int>& postorder, unordered_map<int,int> &mp){
        if(ps > pe or is > ie) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);

        int inroot = mp[postorder[pe]];
        int numsleft = inroot - is;

        root->left = build(is, inroot-1, inorder, ps, ps+ numsleft - 1, postorder, mp);
        root->right = build(inroot+1, ie, inorder, ps + numsleft, pe - 1, postorder, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int m = postorder.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return build(0, n-1, inorder, 0, m-1, postorder, mp);
    }
};