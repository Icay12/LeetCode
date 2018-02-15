class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        if(n > 10)
            return 0;
        if(n == 1)
            return 10;
        int preres = 10;
        int pre = 9;
        for(int i = 9; i > 10 - n; --i) {
            pre *= i;
            preres += pre;
            
        }
        return preres;
    }
};