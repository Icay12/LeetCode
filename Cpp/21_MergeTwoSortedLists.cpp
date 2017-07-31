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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(INT_MIN);
        ListNode* former = head;
        while(l1 != NULL && l2 != NULL) {
            ListNode* p = new ListNode(INT_MIN);
            if(l1->val > l2->val) {
                p->val = l2->val;
                l2 = l2->next;
            }
            else {
                p->val = l1->val;
                l1 = l1->next;
            }
            former->next = p;
            former = p;
        }
        ListNode* l;
        if(l1 != NULL) {
            l = l1;
        }
        else {
            l = l2;
        }
        while(l != NULL) {
            ListNode* p = new ListNode(l->val);
            former->next = p;
            former = p;
            l = l->next;
        }
        return head->next;
    }
};