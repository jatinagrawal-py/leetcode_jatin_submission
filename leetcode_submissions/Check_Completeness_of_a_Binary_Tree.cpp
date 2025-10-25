class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> pq;
        pq.push(root);
        bool seenNull = false;

        while (!pq.empty()) {
            TreeNode* node = pq.front();
            pq.pop();

            if (node == nullptr) {
                seenNull = true; // If we see a null node, all subsequent nodes must be null.
            } else {
                if (seenNull) {
                    return false; // If a non-null node appears after a null, it's not a complete tree.
                }
                pq.push(node->left);
                pq.push(node->right);
            }
        }
        return true;
    }
};
