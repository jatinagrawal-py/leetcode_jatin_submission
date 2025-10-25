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
    vector<string>hehe;
    void solve(TreeNode* root , string i){
        if(!root ){
            return;
        }
        if(root->left==NULL && root->right==NULL ){
            i  = i+to_string(root->val);
            hehe.push_back(i);
            return;
        }
        i  = i+to_string(root->val);
        solve(root->left , i);
        solve(root->right , i);

        return;

    }
    int sumNumbers(TreeNode* root) {
        solve(root , "");
        int sum = 0;
        for(auto it:hehe){
            sum+=(stoi(it));
        }

        return sum;
    }
};