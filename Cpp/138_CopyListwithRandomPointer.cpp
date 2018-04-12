/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *oldhead = head;
        RandomListNode *newhead = NULL;
        RandomListNode *pre = NULL;
        unordered_map<RandomListNode*, RandomListNode*> imap;
        while(head != NULL) {
            RandomListNode *cur = new RandomListNode(head->label);

            if(newhead == NULL)
                newhead = cur;
            else
                pre->next = cur;
            imap[head] = cur;
            head = head->next;
            pre = cur;
        }
        head = oldhead;
        while(head != NULL) {
            if(head->random != NULL)
                imap[head]->random = imap[head->random];
            head = head->next;
        }
        
        return newhead;
    }
};

// without map
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        
        RandomListNode *oldhead = head;
        RandomListNode *newhead = NULL;

        //copy the sequence
        while(head != NULL) {
            RandomListNode *cur = new RandomListNode(head->label);
            cur->next = head->next;
            head->next = cur;
            head = head->next->next;
        }

        head = oldhead;
        //copy random
        while(head != NULL) {
            if(head->random != NULL)
                head->next->random = head->random->next;
            head = head->next->next;
        }

        head = oldhead;
        newhead = head->next;
        RandomListNode *cur = newhead;
        
        while(head != NULL) {
            head->next = head->next->next;
            //notice here
            if(head->next == NULL)
                break;
            cur->next = cur->next->next;
            
            head = head->next;
            cur = cur->next;
        }

        return newhead;
    }
};