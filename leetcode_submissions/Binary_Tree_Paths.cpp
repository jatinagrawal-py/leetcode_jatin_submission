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
    vector<string> ans;

    void solve(TreeNode* root , string path){
        if(root==NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            ans.push_back(path + to_string(root->val));
            return;
        }

        solve(root->left , path + to_string(root->val) + "->");
        solve(root->right , path + to_string(root->val) + "->" );


        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root,"");

        return ans;
    }
};