/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void BHUVANlundHAI(TreeNode* root , unordered_map<TreeNode*,TreeNode*>&parent){
        if(root==NULL)return ;

        queue<TreeNode*>pq;
        pq.push(root);

        while(!pq.empty()){
            int size = pq.size();

            while(size--){
                TreeNode* node = pq.front();
                pq.pop();

                if(node->left){
                    parent[node->left]=node;
                    pq.push(node->left);
                }
                if(node->right){
                    parent[node->right]=node;
                    pq.push(node->right);
                }
            }
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent; // node -> parent relation;

        BHUVANlundHAI(root , parent); // ye parent find karega sab ke bsdk

        queue<TreeNode*>pq;
        pq.push(target);
        unordered_set<TreeNode*>vis;
        vis.insert(target);

        int dis = 0;

        while(!pq.empty()){
            int size = pq.size();
            if(dis==k)break;
            dis++;

            while(size--){
                TreeNode* node = pq.front();
                pq.pop();

                if(node->left!=NULL && vis.find(node->left)==vis.end()){
                    pq.push(node->left);
                    vis.insert(node->left);
                }
                if(node->right!=NULL && vis.find(node->right)==vis.end()){
                    pq.push(node->right);
                    vis.insert(node->right);
                }
                if(parent.find(node)!=parent.end() && vis.find(parent[node])==vis.end()){
                    pq.push(parent[node]);
                    vis.insert(parent[node]);
                }
            }
        }

        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.front()->val);
            pq.pop();
        }

        return ans;
    }
};