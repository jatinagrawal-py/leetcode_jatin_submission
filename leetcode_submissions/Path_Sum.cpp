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
    bool solve(TreeNode* root , int target , int sum){
        if(root==NULL){
            return false;
        }
        sum+=root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==target)
           { return true;}
           else{
            return false;
           }
        }
        
        bool lefty = solve(root->left , target , sum);
        bool righty = solve(root->right , target , sum);
        
        return lefty||righty;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root , targetSum , 0);
    }
};