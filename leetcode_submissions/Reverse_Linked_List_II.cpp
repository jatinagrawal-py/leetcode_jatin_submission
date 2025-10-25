class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        
        for (int i = 1; i < left; ++i) {
            prev = curr;
            curr = curr->next;
        }

        
        ListNode* connect = prev;      
        ListNode* tail = curr;        
        ListNode* next = nullptr;

        for (int i = 0; i < right - left + 1; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        
        if (connect) {
            connect->next = prev;
        } else {
            head = prev;  
        }

        tail->next = curr;

        return head;
    }
};
