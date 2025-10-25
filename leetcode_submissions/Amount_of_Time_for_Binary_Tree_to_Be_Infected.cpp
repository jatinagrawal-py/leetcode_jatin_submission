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

    bool findtarget(TreeNode* root, int start ,TreeNode* &target){
        if(root==NULL)return false;

        if(root->val==start){
            target = root;
            return true;
        }

        if(findtarget(root->left,start,target))return true;
        if(findtarget(root->right,start,target))return true;

        return false;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent; // node -> parent relation;

        BHUVANlundHAI(root , parent); // ye parent find karega sab ke bsdk

        TreeNode* target;

        findtarget(root,start,target);

        queue<TreeNode*>pq;
        pq.push(target);
        unordered_set<TreeNode*>vis;
        vis.insert(target);

        int ans = -1;        

        while(!pq.empty()){
            int size = pq.size();

            ans++;

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

        return ans;
    }
};