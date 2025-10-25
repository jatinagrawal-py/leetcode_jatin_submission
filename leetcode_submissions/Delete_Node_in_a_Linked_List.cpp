/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * temp = node->next;
        while(temp->next != NULL){
            int x = node->val;
            node->val = temp->val;
            temp->val = x;
            node = temp;
            temp = temp->next;
        }
        int x = node->val;
        node->val = temp->val;
        temp->val = x;
        node->next = NULL;
    }
};