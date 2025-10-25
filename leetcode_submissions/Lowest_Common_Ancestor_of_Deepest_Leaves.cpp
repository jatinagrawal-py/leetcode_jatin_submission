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
    int maxidepth=0;
    unordered_map<int,int>mpp;
    void depth(TreeNode* root , int d ){

        if(root==NULL){
            return;
        }
        mpp[root->val]=d;
        maxidepth = max(maxidepth,d);

        depth(root->left,d+1);
        depth(root->right,d+1);

    }
    TreeNode* lca(TreeNode* root){
        if(root==NULL){
            return root;
        }
        if(mpp[root->val]==maxidepth){
            return root;
        }
        
        TreeNode* l = lca(root->left);
        TreeNode* r = lca(root->right);

        if(l!=NULL && r!=NULL){
            return root;
        }

        if(l!=NULL){
            return  l;
        }

        return r;
        
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // common ancestor nikalna hai laude aur woh deepest khud ka toh hoga hi no doubt ancestor toh bus toh phir 

        depth(root, 0); 

        return lca(root);
    }
};