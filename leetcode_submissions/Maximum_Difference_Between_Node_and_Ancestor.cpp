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
    
    int solve(TreeNode* root , int maxi , int mini){
        if(root==NULL){
           return abs(maxi-mini);
        }
        maxi = max(root->val , maxi);
        mini = min(root->val , mini);
        int lh = solve(root->left ,maxi , mini );
        int rh = solve(root->right , maxi , mini);
        
        return max(lh,rh);
    }
    int maxAncestorDiff(TreeNode* root) {
        return solve(root , root->val , root->val);
    }
};