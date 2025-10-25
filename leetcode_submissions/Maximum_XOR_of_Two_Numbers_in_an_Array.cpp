class Solution {

    struct TrieNode {
        TrieNode* child[2] = {nullptr};
    };

    TrieNode* root = new TrieNode();

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit]) {
                node->child[bit] = new TrieNode();
            }
            node = node->child[bit];
        }
    }

    int findMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;
            if (node->child[opposite]) {
                maxXOR |= (1 << i);
                node = node->child[opposite];
            } else {
                node = node->child[bit];
            }
        }
        return maxXOR;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        int maxResult = 0;
        insert(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            maxResult = max(maxResult, findMaxXOR(nums[i]));
            insert(nums[i]);
        }

        return maxResult;
    }
};
