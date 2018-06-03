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
        ListNode* prev = head, *cur = head;

        while(cur != NULL) {
            if(cur != head) {
                if(cur->val == prev->val) {
                    prev->next = cur->next;
                    cur->next = NULL;
                    cur = prev;
                }
                else {
                    prev = prev->next;
                }
            }
            cur = cur->next;
            
        }
        
        return head;
    }
};