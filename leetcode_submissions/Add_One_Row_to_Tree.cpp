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
    void solve(TreeNode* root, int val, int depth , int i){
        if(root==NULL){
            return;
        }
        if(depth-1==i){
            TreeNode* newroot1 = new TreeNode(val);
            TreeNode* newroot2 = new TreeNode(val);
            if(root->left!=NULL){
                newroot1->left = root->left;
            }
            if(root->right!=NULL){
                newroot2->right = root->right;
            }
            root->left = newroot1;
            root->right = newroot2;
            return;
        }
        solve(root->left , val , depth , i+1);
        solve(root->right , val , depth , i+1);

        return;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
           TreeNode* newroot = new TreeNode(val);
           newroot->left = root;
           return newroot; 
        }

        solve(root , val , depth , 1);
        return root;
    }
};