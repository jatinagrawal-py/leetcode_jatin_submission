class Solution {
public:
    bool solve(TreeNode* root){
        if(root == NULL) return false;

        bool leftHasOne = solve(root->left);
        bool rightHasOne = solve(root->right);

        if (!leftHasOne) root->left = NULL;
        if (!rightHasOne) root->right = NULL;

        return root->val == 1 || leftHasOne || rightHasOne;
    }

    TreeNode* pruneTree(TreeNode* root) {
        if (!solve(root)) return NULL; 
        return root;
    }
};
