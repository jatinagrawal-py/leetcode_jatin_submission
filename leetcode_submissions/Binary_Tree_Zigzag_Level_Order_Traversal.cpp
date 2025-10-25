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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result ;
        if(root==NULL){
            return result;
        }
        bool leftright = true;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            // Get the number of nodes
            // at the current level
            int size = q.size();
            
            // Vector to store the values
            // of nodes at the current level
            vector<int> row(size);
            
            // Traverse nodes at 
            // the current level
            for(int i = 0; i < size; i++){
                // Get the front node
                // from the queue
                TreeNode* node = q.front();
                q.pop();
                
                // Determine the index to insert the node's
                // value based on the traversal direction
                int index = leftright ? i : (size - 1 - i);
                
                // Insert the node's value at
                // the determined index
                row[index] = node->val;
                
                // Enqueue the left and right
                // children if they exist
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            
            // Switch the traversal
            // direction for the next level
            leftright = !leftright;
            
            // Add the current level's
            // values to the result vector
            result.push_back(row);
        }
        
        // Return the final result of
        // zigzag level order traversal
        return result;
        }
    
};