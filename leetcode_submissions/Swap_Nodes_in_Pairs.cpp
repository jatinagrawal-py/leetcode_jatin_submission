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
    ListNode* swapPairs(ListNode* head) {

        if(head==NULL || head->next==NULL)return head;
        
        ListNode* temp = head;
        ListNode * prev = NULL;

        int i = 0;

        while(temp!=NULL && temp->next!=NULL){

            ListNode* temp2 = temp->next;
            ListNode* temp1 = temp;
            temp = temp2->next;

            temp1->next = temp;
            temp2->next = temp1;
            if(prev!=NULL){
                prev->next = temp2;
            }
            prev = temp1;

            if(i==0){
                head = temp2;
            }
            i++;
        }
        

        return head;
    }
};