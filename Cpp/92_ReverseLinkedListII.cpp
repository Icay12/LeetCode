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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* begin = head, *end = head;
        ListNode* prevb = NULL, *preve = NULL;
        int cnt = 1;
        while(m > cnt) {
            prevb = begin;
            begin = begin->next;
            cnt++;
        }
        end = begin;
        while(n > cnt) {
            preve = end;
            end = end->next;
            // cout << end->val << endl;
            //switch begin && end
            preve->next = end->next;
            end->next = begin;
            
            begin = end;
            end = preve;
            
            cnt++;
        }
        
        if(prevb != NULL) {
            prevb->next = begin;
            return head;
        }
        else
            return begin;
    }
};