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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }
        while(lists.size() > 1) {
            lists.push_back(merge2Lists(lists[0],lists[1]));
            lists.erase(lists.begin()); //begin(),not front()
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(INT_MIN);
        ListNode* former = head;
        while(l1 && l2) {
            if(l1->val > l2->val) {
                former->next = l2;
                l2 = l2->next;
            }
            else {
                former->next = l1;
                l1 = l1->next;
            }
            former = former->next;
        }
        former->next = l1? l1 : l2;
        return head->next;
    }
};