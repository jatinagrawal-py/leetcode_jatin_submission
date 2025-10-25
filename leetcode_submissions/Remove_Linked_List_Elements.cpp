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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* dummytemp = dummy;
        ListNode* temp = head;

        while(temp!=NULL){
            if(temp->val!=val){
                dummytemp->next=temp;
                dummytemp = temp;
                temp= temp->next;
                dummytemp->next=NULL;
            }
            else{
                temp= temp->next;
            }
        }

        return dummy->next;
    }
};