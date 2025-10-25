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
    vector<TreeNode *>hehe;
    TreeNode* solve(TreeNode* root , unordered_set<int>&st){
        if(root==NULL){
            return NULL;
        }
        root->left = solve(root->left , st);
        root->right = solve(root->right,st);

        if(st.find(root->val)!=st.end()){
            if(root->left!=NULL){
                hehe.push_back(root->left);
            }
            if(root->right!=NULL){
                hehe.push_back(root->right);
            }
            return NULL;
        }
        else
        {return root;}
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>st(to_delete.begin(),to_delete.end());
        solve(root,st);
        if(st.find(root->val)==st.end()){
            hehe.push_back(root);
        }

        return hehe;
    }
};