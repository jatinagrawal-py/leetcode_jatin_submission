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
    vector<vector<int>>hehe;
    vector<int>temp;
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            temp.push_back(root->val);
        }
        solve(root->left);
        solve(root->right);

        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        solve(root1);
        hehe.push_back(temp);
        temp.clear();
        solve(root2);
        hehe.push_back(temp);

        return hehe[0]==hehe[1];
    }
};