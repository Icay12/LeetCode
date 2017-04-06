#include <iostream>
using namespace std;
 

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
	 ListNode(){};
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* thisOne = l1;
		ListNode* thisTwo = l2;
		ListNode* resultHead = new ListNode(0);
		ListNode* resultPointer = resultHead;
		int flag = 0;
		while(thisOne != NULL || thisTwo != NULL || flag != 0) {
			int sum = 0;
			if(thisOne != NULL) {
				sum += thisOne->val;
				thisOne = thisOne->next;
			}
			if(thisTwo != NULL) {
				sum += thisTwo->val;
				thisTwo = thisTwo->next;
			}
			if(flag != 0) {
				sum += flag;
			}
			ListNode* newNode = new ListNode(sum%10);
			flag = sum / 10;
			resultPointer->next = newNode;
			resultPointer = resultPointer->next;
		}
		return resultHead->next;
    }
};
int main()
{
	ListNode* one = new ListNode(1);
	ListNode* two = new ListNode(9);
	ListNode* result;
	Solution* S = new Solution();
	result = S->addTwoNumbers(one,two);

	while(result!=NULL) {
		cout<<result->val<<" ";
		result = result->next;
	}

	return 0;

}