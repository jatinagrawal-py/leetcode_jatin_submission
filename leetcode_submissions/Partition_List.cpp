/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* chota = new ListNode(-1);
        ListNode* chotahead = chota;
        ListNode* bada = new ListNode(-1);
        ListNode* badahead = bada;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val<x){
                chota->next = temp;
                chota = temp;
                temp= temp->next;
                chota->next=NULL;
            }
            else{
                bada->next = temp;
                bada = temp;
                temp= temp->next;
                bada->next=NULL;
            }
        }
        chota->next = badahead->next;
        return chotahead->next;
    }
};