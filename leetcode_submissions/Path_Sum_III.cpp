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
    unordered_map<long long , int>mpp;
    int count = 0;

    void solve(TreeNode* root, int targetSum , long long sum){
        if(root==NULL)return;

        sum+=root->val;
        long long rem = sum - targetSum;

        if(mpp.find(rem)!=mpp.end()){
            count+=mpp[rem];
        }

        mpp[sum]++;

        solve(root->left , targetSum,sum);
        solve(root->right , targetSum,sum);

        mpp[sum]--;

        return ;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mpp[0]=1;
        solve(root,targetSum ,(long long) 0);
        return count;
    }
};