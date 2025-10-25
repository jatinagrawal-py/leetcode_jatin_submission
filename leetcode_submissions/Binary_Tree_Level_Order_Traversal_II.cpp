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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>pq;
        vector<vector<int>>ans;
        pq.push(root);
        while(!pq.empty()){
            int si = pq.size();
            vector<int>temp;
            while(si--){
                TreeNode* node = pq.front();
                pq.pop();
                if(node!=NULL){
                     temp.push_back(node->val);
                }
                if(node->left!=NULL){
                    pq.push(node->left);
                }
                if(node->right!=NULL){
                    pq.push(node->right);
                }
            }
            ans.push_back(temp);
        }

        int i = 0;
        int j = ans.size()-1;
        while(i<j){
            vector<int>temp = ans[i];
            ans[i] = ans[j];
            ans[j] = temp;
            i++;
            j--;
        }

        return ans;
    }
};