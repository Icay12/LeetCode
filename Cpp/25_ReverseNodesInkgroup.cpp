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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //do not forget
        if(head == NULL || k == 1) {
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = head, *pre = dummy, *nex;
        int total = 0;
        while(current) {
            current = current->next;
            total+=1;
        }
        while(total >= k) {
            current = pre->next;
            nex = current->next;
            for(int i = 0; i < k-1; ++i) {
                current->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = current->next;  // 2 1 3
            }
            pre = current;
            total -= k;
        }
        return dummy->next;
    }
};