/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//map
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head != NULL) {
            if(s.count(head) != 0)
                return true;
            s.insert(head);
            head = head->next;
        }
        return false;
    }
};

//two pointer
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p2 != NULL) {
            p2 = p2->next;
            if(p2 == NULL)
                return false;
            p2 = p2->next;
            p1 = p1->next;
            if(p1 == p2)
                return true;
            
        }
        
        return false;
    }
};