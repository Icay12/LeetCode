class Solution {
public:
    int calculate(string s) {
        stack<int> myStack;
        int tmp = 0;
        int sign = '+';
        for(int i = 0; i < s.size(); ++i) {
            cout << s[i] << endl;
            if(isdigit(s[i])) {
                tmp = tmp * 10 + (s[i] - '0');
            }
            // if i is the last index, should push the last number into the stack
            if(!isdigit(s[i]) && s[i] != ' ' || i == (int)s.size()-1) {
                
                if(sign == '+') {
                    myStack.push(tmp);
                    cout << "+" << myStack.top() << endl;
                }
                else if(sign == '-') {
                    
                
                    myStack.push(-tmp);
                    cout << "-" << myStack.top() << endl;
                }
                else if(sign == '*') {
                    int top = myStack.top();
                    myStack.pop();
                    tmp *= top;
                    myStack.push(tmp);
                    cout << "*" <<myStack.top() << endl;
                }
                else if(sign == '/') {
                    int top = myStack.top();
                    myStack.pop();
                    tmp = top / tmp;
                    myStack.push(tmp);
                    cout << "/" <<myStack.top() << endl;
                }
                tmp = 0;
                sign = s[i];
            }
        }
        // myStack.push(tmp);
        // cout << myStack.top() << endl;
        int res = 0;
        while(!myStack.empty()) {
            // cout << myStack.top() << endl;
            res += myStack.top();
            myStack.pop();
        }
        return res;
    }
};