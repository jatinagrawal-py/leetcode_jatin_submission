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
    long sum = 0;
    long maxp = 0;
    int summ(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int lh = summ(root->left);
        int rh = summ(root->right);
        sum = lh + rh + root->val;
        return sum;
    }
    int maxi(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int lh = maxi(root->left);
        int rh = maxi(root->right);

        long subtreesum = root->val + lh + rh;
        maxp = max(maxp , (sum-subtreesum)*subtreesum);

        return subtreesum;
    }
    int maxProduct(TreeNode* root) {
        summ(root);
        maxi(root);


        return maxp%1000000007;
    }
};