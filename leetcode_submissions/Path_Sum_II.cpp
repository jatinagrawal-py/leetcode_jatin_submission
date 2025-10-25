class Solution {
public:
    vector<vector<int>> hehe;

    void solve(TreeNode* root, int target, int sum, vector<int> res) {
        if (!root) return;

        res.push_back(root->val);
        sum += root->val;

        if (!root->left && !root->right && sum == target) {
            hehe.push_back(res);
        }

        solve(root->left, target, sum, res);
        solve(root->right, target, sum, res);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        hehe.clear(); 
        solve(root, targetSum, 0, {});
        return hehe;
    }
};
