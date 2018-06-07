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
    ListNode* partition(ListNode* head, int x) {
        ListNode* fakehead = new ListNode(0);
        fakehead->next = head;
        ListNode* prev = fakehead;
        ListNode* cur = head;
        ListNode* pcur = fakehead;
        while(cur != NULL) {
            if(cur->val < x) {
                if(cur == head || cur == prev->next) {
                    prev = prev->next;
                    pcur = cur;
                    cur = cur->next;
                }
                else {
                    pcur->next = cur->next;
                    cur->next = prev->next;
                    prev->next = cur;
                    prev = prev->next;
                    cur = pcur->next;
                    
                }
            }
            else {
                pcur = cur;
                cur = cur->next;
            }
            
        }
        return fakehead->next;
    }
};