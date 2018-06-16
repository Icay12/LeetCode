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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* lA = headA;
        ListNode* lB = headB;
        int lenA = 0;
        int lenB = 0;
        while(lA != NULL) {
            lenA++;
            lA = lA->next;
        }
        while(lB != NULL) {
            lenB++;
            lB = lB->next;
        }
        if(lenB == 0 || lenA == 0)
            return NULL;
        lA = headA;
        lB = headB;
        while(lenA > lenB) {
            lenA--;
            lA = lA->next;
        }
        while(lenB > lenA) {
            lenB--;
            lB = lB->next;
        }
        ListNode* res = lA;
        while(lA != NULL) {
            if(lA->val != lB->val) {
                res = lA->next;
            }
            lA = lA->next;
            lB = lB->next;
        }
        return res;
    }
};