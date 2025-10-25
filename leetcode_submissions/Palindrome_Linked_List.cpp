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
    ListNode* reversee(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // 1-1-1-1 // 1-1-1-1-1-1
        // 1-1-1
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* slowfront = slow->next;
        slow->next = NULL;
        ListNode* reversehead = reversee(slowfront);

        ListNode* temp = head;

        while(head!=NULL && reversehead!=NULL){
            if(head->val!=reversehead->val)return false;
            head = head->next;
            reversehead = reversehead->next;
        }

        return true;

    }
};