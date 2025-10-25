/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * temp =  head;

        while(temp!=NULL){
            Node * copynode = new Node(temp->val);
            copynode->next = temp->next;
            temp->next = copynode;
            temp = temp->next->next;
        }

        temp = head;
        while(temp!=NULL){
            Node * copynode = temp->next;
            if(temp->random==NULL){
                copynode->random = NULL;
            }
            else copynode->random = temp->random->next;
            temp = temp->next->next;
        }

        temp = head;
        Node* dummyNode = new Node(-1);   
    // Initialize a result pointer
    Node* res = dummyNode;             

    while(temp != NULL){
        // Creating a new List by
        // pointing to copied nodes
        res->next = temp->next;
        res = res->next;

        // Disconnect and revert back to the
        // initial state of the original linked list
        temp->next = temp->next->next;
        temp = temp->next;
    }
    
     // Return the deep copy of the
     // list starting from the dummy node
    return dummyNode->next;  

    }
};