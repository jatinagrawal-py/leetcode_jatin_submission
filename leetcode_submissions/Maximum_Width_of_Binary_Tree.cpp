class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*, unsigned long long>> dq;
        dq.push_back({root, 0});

        int ans = 1;

        while (!dq.empty()) {
            int si = dq.size();
            unsigned long long idx1 = dq.front().second;
            unsigned long long idx2 = dq.back().second;

            ans = max(ans, static_cast<int>(idx2 - idx1 + 1));

            while (si--) {
                TreeNode* u = dq.front().first;
                unsigned long long idx = dq.front().second ; 
                dq.pop_front();

                if (u->left)
                    dq.push_back({u->left, 2 * idx + 1});
                if (u->right)
                    dq.push_back({u->right, 2 * idx + 2});
            }
        }

        return ans;
    }
};
