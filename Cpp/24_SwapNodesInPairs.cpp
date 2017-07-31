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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = dummy;
        while(current->next && current->next->next) {
            ListNode *former = current->next;
            ListNode *later = current->next->next;
            former->next = later->next;
            current->next = later;
            later->next = former;
            current = current->next->next;
        }
        return dummy->next;
    }
};