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
    ListNode* rotateRight(ListNode* head, int k) {
           if (!head || !head->next || k == 0) return head; // Handle edge cases

    // Step 1: Count the number of nodes in the list
    int n = 1;
    ListNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        n++;
    }

    // Step 2: Optimize rotations
    k = k % n;
    if (k == 0) return head; // No rotation needed

    // Step 3: Find the new head
    int stepsToNewHead = n - k; // The position of the new head
    ListNode* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    // Step 4: Update pointers to rotate the list
    ListNode* newHead = newTail->next;
    newTail->next = NULL;
    tail->next = head;

    return newHead;
    }
};