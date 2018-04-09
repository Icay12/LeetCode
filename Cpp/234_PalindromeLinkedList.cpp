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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode* one = head; // one step
        ListNode* two = head; // two steps
        ListNode* pre = head;
        // find middle node
        while(two != NULL && two->next != NULL) {
            pre = one;
            one = one->next;
            two = two->next->next;
        }
        if(two != NULL)
            one = one->next;
        // one is the first of the second half
        //A->B->C->D
        ListNode* tmp = NULL;
        ListNode* halfhead = one;
        
        //reverse the second half list
        while(one != NULL && one->next != NULL) {
            tmp = one->next;
            pre->next = tmp;
            one->next = tmp->next;
            tmp->next = halfhead;
            halfhead = tmp;
        }
        
        // compare
        ListNode* half1 = head;
        ListNode* half2 = halfhead;
        while(half2 != NULL) {
            if(half1->val != half2->val)
                return false;
            half1 = half1->next;
            half2 = half2->next;
        }
        return true;
        
        
    }
};