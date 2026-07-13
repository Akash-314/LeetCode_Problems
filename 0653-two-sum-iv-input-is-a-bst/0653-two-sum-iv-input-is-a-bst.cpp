class Solution {
public:
    void inorder(TreeNode* root, vector<int> &in){
        if(root == NULL) return;
        inorder(root->left, in);
        if(root != NULL) in.push_back(root->val);
        inorder(root->right, in);
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root || (!root->left && !root->right)) return false;
        vector<int> in;
        in.clear();
        inorder(root, in);
        int i = 0, j = in.size()-1;
        while(i < j){
            int sum = in[i] + in[j];
            cout<<sum<<endl;
            if(sum == k) return true;
            if(sum > k) j--;
            else if(sum < k) i++;
        }
        return false;
    }
};