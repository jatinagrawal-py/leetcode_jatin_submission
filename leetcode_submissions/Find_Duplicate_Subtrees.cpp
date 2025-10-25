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
    unordered_map<string, int> subtreeCount;
    vector<TreeNode*> result;

    string solve(TreeNode* root) {
        if (!root) return "#";

        string left = solve(root->left);
        string right = solve(root->right);

        string serial = left + "," + right + "," + to_string(root->val);

        if (++subtreeCount[serial] == 2) {
            result.push_back(root); 
        }

        return serial;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return result;
    }
};
