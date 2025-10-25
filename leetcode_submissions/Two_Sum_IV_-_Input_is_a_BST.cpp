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
    stack<TreeNode*>stn;
    stack<TreeNode*>stp;

    void pushnext(TreeNode* root){
        while(root!=NULL){
            stn.push(root);
            root=root->left;
        }
    }

    void pushprev(TreeNode* root){
         while(root!=NULL){
            stp.push(root);
            root=root->right;
        }
    }

    int next(){
        TreeNode* root = stn.top();
        stn.pop();
        pushnext(root->right);
        return root->val;
    }
    int prev(){
        TreeNode* root = stp.top();
        stp.pop();
        pushprev(root->left);
        return root->val;
    }
    bool findTarget(TreeNode* root, int k) {
        pushnext(root);
        pushprev(root);
        int chota = next();
        int bada = prev();

        while(chota<bada){
            int sum = chota + bada;

            if(sum==k)return true;

            if(sum>k){
                bada = prev();
            }
            else{
                chota = next();
            }
        }

        return false;
    }
};