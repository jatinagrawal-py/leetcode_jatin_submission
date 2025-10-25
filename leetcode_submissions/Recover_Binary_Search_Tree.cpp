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
    void inorder(TreeNode* root , TreeNode* &first,TreeNode* &middle,TreeNode* &last,TreeNode* &prev){
        if(root==NULL)return;

        inorder(root->left,first,middle,last,prev);

        if(prev!=NULL){
            if(prev->val > root->val){
                if(first==NULL){
                    first = prev;
                    middle = root;
                }
                else{
                    last = root;
                }
            }
        }
        prev = root;

        inorder(root->right,first,middle,last,prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* first= NULL;
        TreeNode* middle = NULL;
        TreeNode* last = NULL;
        TreeNode* prev = NULL;

        inorder(root,first,middle,last,prev);

        if(last==NULL){
            first->val = first->val^middle->val;
            middle->val = first->val^middle->val;
            first->val = first->val^middle->val;
        }
        else{
            first->val = first->val^last->val;
            last->val = first->val^last->val;
            first->val = first->val^last->val;
        }
    }
};