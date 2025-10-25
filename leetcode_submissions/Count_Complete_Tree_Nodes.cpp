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
    int count = 0;
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        count++;
        solve(root->left);
        solve(root->right);
    }
    int countNodes(TreeNode* root) {
        solve(root);
        return count;
    }
};