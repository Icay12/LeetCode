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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        // remove duplicates in the head
        ListNode* cur = head->next;
        while(cur != NULL && cur->val == head->val) {
            while(cur != NULL && cur->val == head->val) {
                cur = cur->next;
            }
            if(cur == NULL)
                return NULL;
            else {
                head = cur;
                cur = cur->next;
            }       
        }
        ListNode* prevprev = head;
        ListNode* prev = head;
        cur = prev->next;
        while(cur != NULL) {
            int isSame = false;
            while(cur != NULL && cur->val == prev->val) {
                isSame = true;
                cur = cur->next;
                prev->next = cur;
            }
            if(cur == NULL) {
                prevprev->next = NULL;
                return head;
            }
            else if(isSame) {
                prevprev->next = cur;
                prev = cur;
                cur = cur->next;
            }
            else{
                prevprev = prev;
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};