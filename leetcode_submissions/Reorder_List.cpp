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
    void solve(ListNode* head , ListNode* &temp , ListNode* prev){
        if(head==NULL){
            return;
        }

        solve(head->next , temp , head);

        if(temp==NULL || temp->next==NULL || temp->next->next==NULL)return;

        ListNode* nexty = temp->next;
        temp->next = head;
        prev->next=NULL;
        head->next = nexty;
        temp = nexty;

        return;
    }
    void reorderList(ListNode* head) {
        ListNode* dummy = head;
        ListNode* prev = NULL;
        solve(head,dummy,prev);
    }
};