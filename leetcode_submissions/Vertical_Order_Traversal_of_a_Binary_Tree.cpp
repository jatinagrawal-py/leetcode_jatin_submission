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
    map<int,vector<pair<int,int>>>mpp;
    void solve(TreeNode* root , int col , int row){
        
        if(root==NULL){
            return;
        }

        mpp[col].push_back({row,root->val});

        solve(root->left , col-1 , row+1);
        solve(root->right , col+1 , row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root , 0 , 0);

        vector<vector<int>>ans;

        for(auto it:mpp){
            vector<pair<int,int>>hehe = it.second;
            sort(hehe.begin(),hehe.end());
            vector<int>ans0;
            for(auto at : hehe){
                ans0.push_back(at.second);
            }
            ans.push_back(ans0);
        }

        return ans;
    }
};