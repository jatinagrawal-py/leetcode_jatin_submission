/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root, TreeNode* subRoot){
        if(root==NULL && subRoot==NULL)return true;
        if(root==NULL || subRoot==NULL)return false;

        if(root->val!=subRoot->val)return false;

        bool lefty = check(root->left , subRoot->left);
        
        bool righty = check(root->right , subRoot->right);

        return lefty&&righty;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)return false;

        if(root->val == subRoot->val){
        if(check(root,subRoot))return true;}

        bool lefty = isSubtree(root->left , subRoot);
        bool righty = isSubtree(root->right , subRoot);

        return lefty||righty;

    }
};