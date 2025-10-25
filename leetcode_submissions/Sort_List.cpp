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
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast  = head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left , ListNode* right){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp1 = left;
        ListNode* temp2 = right;
        ListNode* temp3 = dummy;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<=temp2->val){
                temp3->next = temp1;
                temp3 = temp1;
                temp1 = temp1->next;
            }
            else{
                temp3->next = temp2;
                temp3 = temp2;
                temp2 = temp2->next;
            }
        }

        if(temp1!=NULL){
            temp3->next = temp1;
        }
        else{
            temp3->next = temp2;
        }

        return dummy->next;
    }

    ListNode* mergesort( ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* mid = middle(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = mergesort(left);
        right = mergesort(right);
        return merge(left , right);

    }

    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};