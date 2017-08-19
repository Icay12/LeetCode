class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> myStack;
        int top = 0;
        int max = 0;
        for(int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                myStack.push(i);
            else {
                if(myStack.empty()) {
                    myStack.push(i);
                }
                else {
                    top = myStack.top();
                    if(s[top] == '(')
                        myStack.pop();
                    else
                        myStack.push(i);
                }
            }
        }
        if(myStack.empty())
            return s.length();
        top = s.size();
        while(!myStack.empty()) {
            int tmp = myStack.top();
            myStack.pop();
            max = max > top - tmp - 1 ? max : top - tmp - 1;
            top = tmp;
        }
        max = max > top? max : top;
        return max;
    }
};