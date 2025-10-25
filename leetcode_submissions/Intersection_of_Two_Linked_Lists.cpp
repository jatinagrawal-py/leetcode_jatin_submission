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
    ListNode *getIntersectionNode(ListNode *heada, ListNode *headb) {
        ListNode * t1 = heada;
        ListNode * t2 = headb;
        while(t1!=t2){
            t1 = t1->next;
            t2=t2->next;
            if(t1==t2)return t1;
            if(t1==NULL)t1=headb;
            if(t2==NULL)t2=heada;
        }
        return t1;
    }
};