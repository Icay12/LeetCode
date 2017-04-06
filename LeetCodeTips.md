###1. Two Sum
use `unordered_map< >`(hashmap in C++) included in `<unordered_map>`

###2. Add Two Numbers
use a structure to define a long number (single-linked list)

```cpp
//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
	 ListNode(){};
     ListNode(int x) : val(x), next(NULL) {}
 };
```
 

###3.* Longest Substring Without Repeating Characters
1. initialize vector 

	```cpp
	vector<int> character(256,-1)
	```
2. use vector for characters to mark the positions
3. there are 256 charaters

###8. String To Integer
complete and extreme cases

1. the `+` and `-` sign
2. characters other than digits
3. max or min value for Integer
	* `Integer.MAX_VALUE`: \\( 2 ^ {31} - 1 \\) or  2147483647 or 0x7FFFFFFF
	

	```cpp
	if(theNumber > Integer.MAX_VALUE/10 || theNumber == Integer.MAX_VALUE/10 && digit > Integer.MAX_VALUE % 10) {
    	if(sign > 0) 
    		return Integer.MAX_VALUE;
    	else
    		return Integer.MIN_VALUE;
	}
	theNumber = theNumber * 10 + digit;
	```

	




