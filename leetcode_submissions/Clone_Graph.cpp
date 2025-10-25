/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node * solve(Node* root,unordered_map<int,Node*>&st){
        Node * head = new Node(root->val);
        st[root->val]=head;

        for(auto it:root->neighbors){
            if(st.find(it->val)==st.end()){
                Node* temp = solve(it,st);
                head->neighbors.push_back(temp);
            }
            else{
                head->neighbors.push_back(st[it->val]);
            }
        }

        return head;
    }

    Node* cloneGraph(Node* node) {
        if(node==NULL) {
            return NULL;
        }
        unordered_map<int,Node*>st;
        if(node->neighbors.empty()){
            Node* temp = new Node(node->val);
            return temp;
        }

        return solve(node,st);
    }
};