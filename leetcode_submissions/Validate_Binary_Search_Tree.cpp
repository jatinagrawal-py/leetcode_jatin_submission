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
    bool check(TreeNode* root , long long lh , long long rh){
        if(root==NULL)return true;

        if(root->val<=lh || root->val>=rh){
            return false;
        }

        bool left = check(root->left , lh , root->val);
        bool right = check(root->right , root->val , rh);

        return left && right;
    }
    bool isValidBST(TreeNode* root) {
      
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};