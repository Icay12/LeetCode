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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* dummy= new ListNode(0);
        dummy->next = head;
        while(head->next != NULL) {
            ListNode* tmp = dummy->next;
            dummy->next = head->next;
            head->next = head->next->next;
            dummy->next->next = tmp;
        }
        return dummy->next;
    }
};