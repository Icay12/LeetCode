// the solution is to remove the "( )" and record the real operation
// for example
// -(1 + 1) = - 1 - 1
//

class Solution {
public:
    int calculate(string s) {
        stack<int> ops;
        int lastsign = 1;
        int num = 0;
        int res = 0;
        ops.push(lastsign);
        for(char c : s) {
            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if(c == '+') {
                res += num * lastsign * ops.top();
                lastsign = 1;
                num = 0;
            }
            else if(c == '-') {
                res += num * lastsign * ops.top();
                lastsign = -1;
                num = 0;
            }
            else if(c == '(') {
                ops.push(lastsign * ops.top());
                lastsign = 1;
                
            }
            else if(c == ')') {
                res += num * lastsign * ops.top();
                lastsign = 1;
                ops.pop();
                num = 0;
            }
         }
        res += num * lastsign * ops.top();
        return res;
    }
};