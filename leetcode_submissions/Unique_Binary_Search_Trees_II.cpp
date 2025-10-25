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

    vector<TreeNode*> solve(int start , int end){
        if(start==end){
            TreeNode* temp = new TreeNode(start);
            return {temp};
        }
        if(start>end)return {NULL};
        vector<TreeNode*> ans;

        for(int i = start;i<=end;i++){
            vector<TreeNode*>leftbst = solve(start,i-1);
            vector<TreeNode*>rightbst = solve(i+1,end);

            for(auto l:leftbst){
                for(auto r:rightbst){
                    TreeNode* temp = new TreeNode(i);
                    temp->left = l;
                    temp->right = r;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};


