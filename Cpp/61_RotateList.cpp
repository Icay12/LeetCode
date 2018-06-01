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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) // note when k == 0
            return head;
        
        ListNode* begin = head, *end = head;
        int cnt = 0;
        while(cnt < k && end != NULL) {
            cnt++;
            end = end->next;
        }
        
        //list length <= k
        if(end == NULL) {
            int len = cnt;
            end = head;
            cnt = k % len; // ensure cnt < k
            if(cnt == 0)  //note when k = n * len
                return head;
            while(cnt > 0) {
                end = end->next;
                cnt--;
            }
        }
        
        ListNode* prevEnd;
        ListNode* prevBegin;
        while(end != NULL) {
            prevBegin = begin;
            prevEnd = end;
            end = end->next;
            begin = begin->next; 
        }
        
        prevBegin->next = NULL;
        prevEnd->next = head;
        
        return begin; 
    }
};