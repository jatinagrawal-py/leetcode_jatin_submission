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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        map<int,pair<ListNode*,int>>mpp;
        ListNode* temp = head;
        
        while(temp!=NULL){
            mpp[temp->val].first = temp;
            mpp[temp->val].second++;
            temp = temp->next;
        }

        ListNode* dummy = new ListNode(-101);
        temp = dummy;

        for(auto it:mpp){
            if(it.second.second==1){
                temp->next = it.second.first;
                it.second.first->next = NULL;
                temp = temp->next;
            }
        }
        
        return dummy->next;
        
    }
};