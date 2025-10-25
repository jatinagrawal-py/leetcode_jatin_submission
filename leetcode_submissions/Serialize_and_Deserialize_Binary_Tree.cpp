/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)return "";
        string ans = "";
        queue<TreeNode*>pq;
        pq.push(root);
        ans+=to_string(root->val);
        ans+=",";

        while(!pq.empty()){
            int size = pq.size();
            while(size--){
                TreeNode* node = pq.front();
                pq.pop();
                

                if(node->left!=NULL){
                    pq.push(node->left);
                    ans+=to_string(node->left->val);
                    ans+=",";
                }
                else{
                    ans+="#,";
                }
                if(node->right!=NULL){
                    pq.push(node->right);
                    ans+=to_string(node->right->val);
                    ans+=",";
                }
                else{
                    ans+="#,";
                }
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;

        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode((int)stoi(str));
        queue<TreeNode*>pq;
        pq.push(root);

        while(!pq.empty()){
            int size = pq.size();
            while(size--){
                TreeNode* node = pq.front();
                pq.pop();
                getline(s,str,',');
                if(str=="#"){
                    node->left=NULL;
                }
                else{
                    TreeNode* lefty = new TreeNode(stoi(str));
                    node->left = lefty;
                    pq.push(lefty);
                }

                getline(s,str,',');
                if(str=="#"){
                    node->right=NULL;
                }
                else{
                    TreeNode* righty = new TreeNode(stoi(str));
                    node->right = righty;
                    pq.push(righty);
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));