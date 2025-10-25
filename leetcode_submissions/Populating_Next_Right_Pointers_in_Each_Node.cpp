/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>pq;
        if(root==NULL)return root;
        pq.push(root);

        while(!pq.empty()){
            int si = pq.size();
            Node* prev = NULL;
            while(si--){
                Node* curr = pq.front();
                pq.pop();
                if(prev!=NULL){
                    prev->next = curr;
                }
                prev = curr;

                if(curr->left!=NULL){
                    pq.push(curr->left);
                }   
                if(curr->right!=NULL){
                    pq.push(curr->right);
                }
            }
        }
        return root;
    }
};